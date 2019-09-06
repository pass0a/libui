#include "ui.h"
#include <stdio.h>
#include <memory>
#include <thread>
int onClosing(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

void onClicked(uiButton *b, void *data)
{
    char msg[32] = "Button is clicked!";
    /*uiLabelSetText(uiLabel(data), msg);*/
    printf(msg);
}

int uithread() {
    uiInitOptions o;
    const char *err;
    uiWindow *w;
    uiGrid *g;
    uiLabel *l;
    uiButton *b;
    memset(&o, 0, sizeof(uiInitOptions));
    err = uiInit(&o);
    if (err != NULL) {
        puts(err);
        uiFreeInitError(err);
        return 1;
    }
    // 创建Window
    w = uiNewWindow("libui", 320, 240, 0);
    uiWindowSetMargined(w, 1);

    // 创建Grid
    g = uiNewGrid();
    uiGridSetPadded(g, 1);
    uiWindowSetChild(w, uiControl(g));

    // 创建Label
    l = uiNewLabel("I am a label.");
    uiGridAppend(g, uiControl(l),
        0, 2, 2, 1,
        1, uiAlignCenter, 1, uiAlignFill);

    // 创建Button，注册按钮点击时的回调函数
    b = uiNewButton("Click me!");
    uiButtonOnClicked(b, onClicked, l);
    uiGridAppend(g, uiControl(b),
        0, 2, 2, 1,
        1, uiAlignCenter, 1, uiAlignEnd);

    // 注册窗口关闭时的回调函数
    uiWindowOnClosing(w, onClosing, NULL);

    // 显示窗口
    uiControlShow(uiControl(w));

    // 启动主循环
    uiMain();
    return 0;
}
int main() {
    //
    
    uithread();
    
    
    return 0;
}