#include "binding.h"
#include <WinSock.h>
#include <ws2bth.h>
struct pa_plugin gp;
static const pa_function_list_entry my_module_funcs[] = {
    { "openFolder", libuiOpenFolder, PA_VARARGS /*nargs*/ },
    { "openFile", libuiOpenFile, PA_VARARGS /*nargs*/ },
    { "init", libuiInit, PA_VARARGS /*nargs*/ },
    { "hook", libuiHook, PA_VARARGS /*nargs*/ },
    { "main", libuiMain, PA_VARARGS /*nargs*/ },
    { "newWindow", libuiNewWindow, PA_VARARGS /*nargs*/ },
    { "windowSetMargined", libuiWindowSetMargined, PA_VARARGS /*nargs*/ },
    { "windowSetChild", libuiWindowSetChild, PA_VARARGS /*nargs*/ },
    { "newGrid", libuiNewGrid, PA_VARARGS /*nargs*/ },
    { "gridSetPadded", libuiGridSetPadded, PA_VARARGS /*nargs*/ },
    { "gridAppend", libuiGridAppend, PA_VARARGS /*nargs*/ },
    { "newLabel", libuiNewLabel, PA_VARARGS /*nargs*/ },
    { "newButton", libuiNewButton, PA_VARARGS /*nargs*/ },
    { "buttonOnClicked", libuiButtonOnClicked, PA_VARARGS /*nargs*/ },
    { "controlShow", libuiControlShow, PA_VARARGS /*nargs*/ },
    { 0, 0, 0 }
};
extern "C" int passoa_init(pa_plugin p) {
    gp = p;
    gp.put_function_list(p.ctx, -1, my_module_funcs);
    return 0;
}
extern "C" int passoa_exit() {
    libuiUnload();
    return 0;
}


