#include "binding.h"
#include <WinSock.h>
#include <ws2bth.h>
struct pa_plugin gp;
static const pa_function_list_entry my_module_funcs[] = {
    { "openFolder", libuiOpenFolder, PA_VARARGS /*nargs*/ },
    { "openFile", libuiOpenFile, PA_VARARGS /*nargs*/ },
    { "init", libuiInit, PA_VARARGS /*nargs*/ },
    { "hook", libuiHook, PA_VARARGS /*nargs*/ },
    { "mainStep", libuiStep, PA_VARARGS /*nargs*/ },
    { "run", libuiRun, PA_VARARGS /*nargs*/ },
    { "newWindow", libuiNewWindow, PA_VARARGS /*nargs*/ },
    { "windowSetMargined", libuiWindowSetMargined, PA_VARARGS /*nargs*/ },
    { "windowSetChild", libuiWindowSetChild, PA_VARARGS /*nargs*/ },
    { "newGrid", libuiNewGrid, PA_VARARGS /*nargs*/ },
    { "newHorizontalBox", libuiNewHorizontalBox, PA_VARARGS /*nargs*/ },
    { "newVerticalBox", libuiNewVerticalBox, PA_VARARGS /*nargs*/ },
    { "boxAppend", libuiBoxAppend, PA_VARARGS /*nargs*/ },
    { "gridSetPadded", libuiGridSetPadded, PA_VARARGS /*nargs*/ },
    { "gridAppend", libuiGridAppend, PA_VARARGS /*nargs*/ },
    { "newLabel", libuiNewLabel, PA_VARARGS /*nargs*/ },
    { "labelSetText", libuiLabelSetText, PA_VARARGS /*nargs*/ },
    { "labelText", libuiLabelText, PA_VARARGS /*nargs*/ },
    { "newButton", libuiNewButton, PA_VARARGS /*nargs*/ },
    { "controlOp", libuiControlOp, PA_VARARGS /*nargs*/ },
    { "newCombobox", libuiNewCombobox, PA_VARARGS /*nargs*/ },
    { "comboboxAppend", libuiComboboxAppend, PA_VARARGS /*nargs*/ },
    { "comboboxSelected", libuiComboboxSelected, PA_VARARGS /*nargs*/ },
    { "comboboxSetSelected", libuiComboboxSetSelected, PA_VARARGS /*nargs*/ },
	{ "newProgressBar", libuiNewProgressBar, PA_VARARGS /*nargs*/ },
	{ "progressBarSetValue", libuiProgressBarSetValue, PA_VARARGS /*nargs*/ },
	{ "msgBox", libuiMsgBox, PA_VARARGS /*nargs*/ },
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


