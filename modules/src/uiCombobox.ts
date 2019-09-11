import uiControl from './uiControl';
import * as bind from './binding';
export class uiCombobox extends uiControl {
	constructor() {
		super(bind.newCombobox());
	}
	append(text: string) {
		bind.comboboxAppend(this.handle, text);
	}
	getSelected() {
		return bind.comboboxSelected(this.handle);
	}
	setSelected(idx: number) {
		bind.comboboxSetSelected(this.handle, idx);
	}
}
