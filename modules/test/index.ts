import * as libui from '../src/index';
import { readdirSync } from 'fs';
import { extname } from 'path';
import { execSync } from 'child_process';
import { decode, encode } from 'iconv-lite';

let handle = [ '.mp3', '.mp4', '.mkv' ];
let r = libui.init();
console.log(r);
let w = libui.newWindow('hello', 800, 480, 0);
libui.windowOnClosing(w, () => {
	console.log('windowClose');
	libui.exit();
});
let g = libui.newGrid();
libui.gridSetPadded(g, 1);
libui.windowSetChild(w, g);
let label1 = libui.newLabel('世界');
let label2 = libui.newLabel('你好');
let label3 = libui.newLabel('hello');
let label4 = libui.newLabel('world');
let xspan = 10;
let yspan = 10;
libui.gridAppend(g, label1, 0, 0, xspan, yspan, 1, libui.uiAlign.uiAlignCenter, 1, libui.uiAlign.uiAlignFill);
libui.gridAppend(g, label2, 0, 2, xspan, yspan, 1, libui.uiAlign.uiAlignCenter, 1, libui.uiAlign.uiAlignFill);
libui.gridAppend(g, label3, 1, 0, xspan, yspan, 1, libui.uiAlign.uiAlignCenter, 1, libui.uiAlign.uiAlignFill);
libui.gridAppend(g, label4, 1, 1, xspan, yspan, 1, libui.uiAlign.uiAlignCenter, 1, libui.uiAlign.uiAlignFill);
libui.controlShow(w);
libui.main();
// let input = libui.openFolder();
// let list = readdirSync(input);
// for (const iterator of list) {
// 	var y = encode(decode(Buffer.from(iterator), 'gbk'), 'utf8');
// 	if (handle.indexOf(extname(y.toString())) > 0) {
// 		console.log(iterator);
// 	}
// }
