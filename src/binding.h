#include "plugin.h"
int libuiOpenFolder(pa_context *ctx);
int libuiOpenFile(pa_context* ctx);
int libuiInit(pa_context *ctx);
int libuiNewWindow(pa_context *ctx);
int libuiMain(pa_context *ctx);
int libuiControlShow(pa_context *ctx);
int libuiWindowSetMargined(pa_context *ctx);
int libuiWindowSetChild(pa_context *ctx);
int libuiWindowOnClosing(pa_context *ctx);
int libuiNewGrid(pa_context* ctx); 
int libuiGridSetPadded(pa_context *ctx);
int libuiGridAppend(pa_context *ctx);
int libuiNewLabel(pa_context *ctx);
int libuiNewButton(pa_context *ctx);
int libuiButtonOnClicked(pa_context *ctx);
void libuiUnload();