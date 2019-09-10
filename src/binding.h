#include "plugin.h"
int libuiOpenFolder(pa_context *ctx);
int libuiOpenFile(pa_context* ctx);
int libuiInit(pa_context *ctx);
int libuiHook(pa_context *ctx);
int libuiNewWindow(pa_context *ctx);
int libuiStep(pa_context *ctx);
int libuiRun(pa_context *ctx);
int libuiControlShow(pa_context *ctx);
int libuiWindowSetMargined(pa_context *ctx);
int libuiWindowSetChild(pa_context *ctx);
int libuiNewGrid(pa_context* ctx); 
int libuiNewVerticalBox(pa_context* ctx);
int libuiNewHorizontalBox(pa_context* ctx);
int libuiBoxAppend(pa_context* ctx);
int libuiGridSetPadded(pa_context *ctx);
int libuiGridAppend(pa_context *ctx);
int libuiNewLabel(pa_context *ctx);
int libuiLabelSetText(pa_context *ctx);
int libuiLabelText(pa_context *ctx);
int libuiNewButton(pa_context *ctx);
void libuiUnload();