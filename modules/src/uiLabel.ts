import uiControl from './uiControl';
import * as bind from './binding';
export class uiLabel extends uiControl {
	constructor(text: string) {
		super(bind.newLabel(text));
	}
	setText(text: string) {
		bind.labelSetText(this.handle, text);
	}
	getText() {
		return bind.labelText(this.handle);
	}
}
