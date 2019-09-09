import { EventEmitter } from 'events';
if ('win32' == process.platform) {
	process.env.Path = process.env.Path + ';' + __dirname;
} else {
	process.env.Path = process.env.Path;
}
const ui = require('./ui.passoa');
declare let passoa_callbacks: any;
export class uiEvent extends EventEmitter {
	static ref = passoa_callbacks.push(uiEvent.onEvent);
	static res = ui.hook(uiEvent.ref);
	static map = new Map<any, uiEvent>();
	readonly handle: any;
	static onEvent(p: any, ev: string) {
		console.log('onEvent', ev);
		let ele = uiEvent.map.get(p);
		if (ele) {
			ele.emit(ev);
		}
	}
	constructor(p: any) {
		super();
		this.handle = p;
		uiEvent.map.set(this.handle, this);
	}
}

export function openFolder() {
	return ui.openFolder();
}
export function openFile() {
	return ui.openFile();
}
export function saveFile() {
	return ui.saveFile();
}

export function init() {
	console.log('ui.init !!!');
	return ui.init();
}
export function exit() {}

export function startLoop() {
	return ui.main();
}
export function controlShow(ptr: any) {
	return ui.controlShow(ptr);
}
export function newWindow(title: string, width: number, heigth: number, isMember: number) {
	return ui.newWindow(title, width, heigth, isMember);
}
export function windowSetMargined(w: any, margined: number) {
	return ui.windowSetMargined(w, margined);
}
export function windowSetChild(w: any, child: any) {
	return ui.windowSetChild(w, child);
}
export function windowOnClosing(ele: any, cb: () => void) {
	let idx = passoa_callbacks.push(cb);
	return ui.windowOnClosing(ele, idx);
}
export function newButton(text: string) {
	return ui.newButton(text);
}
export function buttonOnClicked(ele: any, cb: () => void) {
	let idx = passoa_callbacks.push(cb);
	return ui.buttonOnClicked(ele, idx);
}

export function newGrid() {
	return ui.newGrid();
}
export function gridSetPadded(g: any, paded: number) {
	return ui.gridSetPadded(g, paded);
}
export enum uiAlign {
	uiAlignFill,
	uiAlignStart,
	uiAlignCenter,
	uiAlignEnd
}
export function gridAppend(
	g: any,
	c: any,
	left: number,
	top: number,
	xspan: number,
	yspan: number,
	hexpand: number,
	halign: uiAlign,
	vexpand: number,
	valign: uiAlign
) {
	return ui.gridAppend(g, c, left, top, xspan, yspan, hexpand, halign, vexpand, valign);
}
export function newLabel(text: string) {
	return ui.newLabel(text);
}
