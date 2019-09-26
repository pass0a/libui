import uiControl from './uiControl';
import * as bind from './binding';

class uiBox extends uiControl {
	private children = new Set<uiControl>();
	constructor(hnd: uiControl) {
		super(hnd);
	}
	onDestroy(control: uiControl) {}

	append(c: uiControl, stretchy: boolean) {
		bind.boxAppend(this.handle, c.handle, stretchy);
	}
	deleteAt(index: number) {}
	getPadded() {}
	setPadded(padded: boolean) {}
}

export class uiVerticalBox extends uiBox {
	constructor() {
		super(bind.newHorizontalBox());
	}
}
export class uiHorizontalBox extends uiBox {
	constructor() {
		super(bind.newVerticalBox());
	}
}
