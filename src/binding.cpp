#include "binding.h"
#include "ui.h"
#include <iostream>
#include <ShlObj.h>
#include <Windows.h>
#include <thread>

extern struct pa_plugin gp;
int gref = -1;
pa_context* gctx=NULL;
void onCall(void* ptr,char* ev) {
    if (gctx) {
        gp.eval_string(gctx, "(passoa_callbacks.call.bind(passoa_callbacks))");
        gp.push_int(gctx, gref);
        gp.push_pointer(gctx, ptr);
        gp.push_string(gctx, ev);
        gp.call(gctx, 3);
        gp.pop(gctx);
    }
}
int libuiHook(pa_context *ctx) {
    if (gp.is_number(ctx, 0)) {
        gref = gp.get_int(ctx,0);
        gctx = ctx;
    }
    return 0;
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
int libuiRun(pa_context *ctx) {
    uiMain();
    return 0;
}
int libuiStep(pa_context *ctx) {
    gp.push_int(ctx,uiMainStep(0));
    return 1;
}

int libuiNewWindow(pa_context *ctx) {
    if (gp.is_string(ctx, 0) && gp.is_number(ctx, 1) && gp.is_number(ctx, 2) && gp.is_number(ctx, 3)) {
        auto ptr =uiNewWindow(gp.get_string(ctx,0),gp.get_int(ctx,1),gp.get_int(ctx,2),gp.get_int(ctx,3));
        uiWindowOnClosing(ptr, [](uiWindow *w, void *data) {
            onCall(w, "close");
            uiQuit();
            return 0;
        }, NULL);
        gp.push_pointer(ctx, ptr);
        return 1;
    }
    return 0;
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
int libuiNewVerticalBox(pa_context* ctx) {
    gp.push_pointer(ctx, uiNewVerticalBox());
    return 1;
}
int libuiNewHorizontalBox(pa_context* ctx) {
    gp.push_pointer(ctx, uiNewHorizontalBox());
    return 1;
}
int libuiBoxAppend(pa_context* ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_pointer(ctx, 1) && gp.is_boolean(ctx, 2)) {
        uiBoxAppend(uiBox(gp.get_pointer(ctx, 0)),
            uiControl(gp.get_pointer(ctx, 1)), gp.get_boolean(ctx, 2));
    }
    return 0;
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
int libuiLabelSetText(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0) && gp.is_string(ctx, 1)) {
        uiLabelSetText(uiLabel(gp.get_pointer(ctx, 0)),gp.get_string(ctx,1));
    }
    return 0;
}
int libuiLabelText(pa_context *ctx) {
    if (gp.is_pointer(ctx, 0)) {
        gp.push_string(ctx,uiLabelText(uiLabel(gp.get_pointer(ctx, 0))));
    }
    return 0;
}

int libuiControl(pa_context *ctx) {

    return 1;
}

int libuiNewButton(pa_context *ctx) {
    if (gp.is_string(ctx, 0)) {
        auto ptr = uiNewButton(gp.get_string(ctx, 0));
        gp.push_pointer(ctx,ptr );
        uiButtonOnClicked(ptr, [](uiButton *b, void *data) {
            onCall(b, "click");
        }, NULL);
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
        uiGridAppend(uiGrid(gp.get_pointer(ctx, 0)), uiControl(gp.get_pointer(ctx, 1)),
            gp.get_int(ctx, 2), gp.get_int(ctx, 3),
            gp.get_int(ctx, 4), gp.get_int(ctx, 5),
            gp.get_int(ctx, 6), gp.get_int(ctx, 7),
            gp.get_int(ctx, 8), gp.get_int(ctx, 9));
    }
    return 0;
}

int libuiControlShow(pa_context *ctx) {
    if(gp.is_pointer(ctx,0)){
        uiControlShow(uiControl(gp.get_pointer(ctx, 0)));
    }
    return 0;
}
void libuiUnload() {
    //uiUninit();
}
