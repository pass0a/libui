#include "binding.h"
#include "ui.h"
#include <iostream>
#include <ShlObj.h>
#include <Windows.h>

extern struct pa_plugin gp;


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
int libuiMain(pa_context *ctx) {
    return 1;
}