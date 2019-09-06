#include "binding.h"
#include "ui.h"
#include <iostream>
#include <ShlObj.h>
#include <Windows.h>
#include <thread>

extern struct pa_plugin gp;
struct CallNode {
    pa_context* ctx;
    int ref;
};
void onCall(CallNode* pcn) {
    gp.eval_string(pcn->ctx, "(passoa_callbacks.callonce.bind(passoa_callbacks))");
    gp.push_int(pcn->ctx, pcn->ref);
    gp.call(pcn->ctx, 1);
    gp.pop(pcn->ctx);
}
int libuiOpenFile(pa_context *ctx) {
    uiWindow* w;
    w = uiNewWindow("Hello", 320, 240, 0);
    char* path=uiOpenFile(w);
    gp.push_string(ctx, path);
    return 1;
}
int libuiOpenFolder(pa_context *ctx)
{
    char szBuffer[MAX_PATH] = { 0 };
    BROWSEINFO bi;
    memset(&bi, 0, sizeof(BROWSEINFO));
    bi.hwndOwner = NULL;
    bi.pszDisplayName = szBuffer;
    bi.lpszTitle = "从下面选择文件或文件夹:";
    bi.ulFlags = BIF_BROWSEINCLUDEFILES;
    LPITEMIDLIST idl = SHBrowseForFolder(&bi);
    if (NULL == idl)
    {
        gp.push_undefined(ctx);
        return true;
    }
    SHGetPathFromIDList(idl, szBuffer);
    gp.push_string(ctx,szBuffer);
    return 1;
}
int libuiInit(pa_context *ctx) {
    uiInitOptions o;
    gp.push_string(ctx, uiInit(&o));
    return 1;
}
int loop_step() {
    return !uiMainStep(0);
}
int libuiMain(pa_context *ctx) {
    gp.push_loop(loop_step);
    return 0;
}
int libuiNewWindow(pa_context *ctx) {
    if (gp.is_string(ctx, 0) && gp.is_number(ctx, 1) && gp.is_number(ctx, 2) && gp.is_number(ctx, 3)) {
        gp.push_pointer(ctx,uiNewWindow(gp.get_string(ctx,0),gp.get_int(ctx,1),gp.get_int(ctx,2),gp.get_int(ctx,3)));
    }
    return 1;
}
int libuiWindowSetMargined(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_number(ctx, 1)) {
        uiWindowSetMargined(uiWindow(gp.get_pointer(ctx, 0)), gp.get_int(ctx, 1));
    }
    return 0;
}
int libuiNewGrid(pa_context* ctx) {
    gp.push_pointer(ctx,uiNewGrid());
    return 1;
}
int libuiGridSetPadded(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_number(ctx, 1)) {
        uiGridSetPadded(uiGrid(gp.get_pointer(ctx, 0)), gp.get_int(ctx, 1));
    }
    return 0;
}
int libuiWindowSetChild(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_pointer(ctx, 1)) {
        uiWindowSetChild(uiWindow(gp.get_pointer(ctx, 0)), uiControl(gp.get_pointer(ctx, 1)));
    }
    return 0;
}

int libuiNewLabel(pa_context *ctx) {
    if (gp.is_string(ctx, 0)) {
        gp.push_pointer(ctx, uiNewLabel(gp.get_string(ctx, 0)));
    }
    return 1;
}

int libuiControl(pa_context *ctx) {

    return 1;
}

int libuiNewButton(pa_context *ctx) {
    if (gp.is_string(ctx, 0)) {
        gp.push_pointer(ctx, uiNewButton(gp.get_string(ctx,0)));
    }
    return 1;
}
void onClicked(uiButton *b, void *data)
{
    CallNode* pcn = (CallNode*)data;
    onCall(pcn);
    delete pcn;
}
int libuiButtonOnClicked(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_number(ctx, 1))
    {
        uiButtonOnClicked(uiButton(gp.get_pointer(ctx, 0)),
            onClicked, new CallNode({ ctx,gp.get_int(ctx,1) }));
    }
    return 1;
}
int libuiGridAppend(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.get_pointer(ctx, 1)) {
        for (size_t i = 2; i < 10; i++)
        {
            if (!gp.is_number(ctx, i)) {
                return 0;
            }
        }
        int left = gp.get_int(ctx,2);
        int top = gp.get_int(ctx, 3);
        uiGridAppend(uiGrid(gp.get_pointer(ctx, 0)), uiControl(gp.get_pointer(ctx, 1)),
            gp.get_int(ctx, 2), gp.get_int(ctx, 3),
            gp.get_int(ctx, 4), gp.get_int(ctx, 5),
            gp.get_int(ctx, 6), gp.get_int(ctx, 7),
            gp.get_int(ctx, 8), gp.get_int(ctx, 9));
    }
    return 0;
}
int onClosing(uiWindow *w, void *data)
{
    CallNode* pcn = (CallNode*)data;
    onCall(pcn);
    delete pcn;
    uiQuit();
    return 1;
}
int libuiWindowOnClosing(pa_context *ctx) {
    if (gp.is_pointer(ctx,0) && gp.is_number(ctx,1))
    {
        uiWindowOnClosing(uiWindow(gp.get_pointer(ctx,0)),
            onClosing, new CallNode({ ctx,gp.get_int(ctx,1) }));
    }
    return 1;
}
int libuiControlShow(pa_context *ctx) {
    if(gp.is_pointer(ctx,0)){
        uiControlShow(uiControl(gp.get_pointer(ctx, 0)));
    }
    return 0;
}
void libuiUnload() {
    uiUninit();
}