import * as ui from '../src/index';
import { uiAlign } from '../src/binding';
let x = new ui.uiWindow('hello', 800, 480, 0);
let g = new ui.uiGrid();
let b1 = new ui.uiButton('你好');
let b2 = new ui.uiButton('你好');
b1.on('click', () => {
	console.log('button click1');
});
b2.on('click', () => {
	console.log('button click2');
});
g.append(b1, 0, 0, 10, 10, 1, uiAlign.uiAlignCenter, 1, uiAlign.uiAlignCenter);
g.append(b1, 1, 1, 10, 10, 1, uiAlign.uiAlignCenter, 1, uiAlign.uiAlignCenter);
x.setChild(new ui.uiGrid());

x.show();
ui.startLoop();
