import { uiWindow, uiButton, uiLabel, startLoop, uiHorizontalBox } from '../src/index';
import { exec } from 'child_process';
let x = new uiWindow('hello', 400, 320, 0);
let g = new uiHorizontalBox();
x.setChild(g);
let label = new uiLabel('请先选择要处理的目录');
let b1 = new uiButton('选择目录');
let b2 = new uiButton('开始处理');
b1.on('click', () => {
	label.setText(x.openFolder());
});
b2.on('click', () => {
	exec('ffmpeg ');
});
// g.append(b1, 0, 0, 1, 1, true, uiAlign.uiAlignFill, true, uiAlign.uiAlignFill);
// g.append(b2, 0, 1, 1, 1, true, uiAlign.uiAlignFill, true, uiAlign.uiAlignFill);
// g.append(b2, 0, 1, 1, 1, true, uiAlign.uiAlignFill, true, uiAlign.uiAlignFill);
g.append(label, false);
g.append(b1, false);
g.append(b2, false);
x.show();
startLoop();
