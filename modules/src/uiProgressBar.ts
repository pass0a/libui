import uiControl from './uiControl';
import * as bind from './binding';
export class uiProgressBar extends uiControl {
	constructor() {
		super(bind.newProgressBar());
	}
	setValue(value: number) {
		bind.progressBarSetValue(this.handle, value);
	}
}
