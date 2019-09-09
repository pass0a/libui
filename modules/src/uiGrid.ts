import uiControl from './uiControl';
import * as bind from './binding';
export class uiGrid extends uiControl {
	constructor() {
		super(bind.newGrid());
	}
	getPadded() {}
	setPadded(value: boolean) {}
	append(
		c: uiControl,
		left: number,
		top: number,
		xspan: number,
		yspan: number,
		hexpand: number,
		halign: bind.uiAlign,
		vexpand: number,
		valign: bind.uiAlign
	) {
		return bind.gridAppend(this.handle, c.handle, left, top, xspan, yspan, hexpand, halign, vexpand, valign);
	}
	insertAt(
		c: uiControl,
		existing: uiControl,
		at: number,
		xspan: number,
		yspan: number,
		hexpand: number,
		halign: number,
		vexpand: number,
		valign: number
	) {}

	onDestroy(control: uiControl) {}
}
