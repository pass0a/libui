import uiControl from './uiControl';
import * as bind from './binding';
export class uiButton extends uiControl {
	constructor(text: string) {
		super(bind.newButton(text));
	}
}
