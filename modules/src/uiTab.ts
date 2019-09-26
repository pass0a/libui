import uiControl from './uiControl';
import * as bind from './binding';
export class uiTab extends uiControl {
	constructor() {
		super(bind.newTab());
	}
	append(text: string, child: uiControl) {
		return bind.tabAppend(this.handle, text, child.handle);
	}
	insertAt(name: string, before: number, child: uiControl) {
		return bind.tabInsertAt(this.handle, name, before, child.handle);
	}
	deleteAt(index: number) {
		return bind.tabDelete(this.handle, index);
	}
	numPages() {
		return bind.tabNumPages(this.handle);
	}
	getMargined(page: number) {
		return bind.tabMargined(this.handle, page);
	}
	setMargined(page: number, margined: boolean) {
		return bind.tabSetMargined(this.handle, page, margined ? 1 : 0);
	}

	onDestroy(control: uiControl) {}
}
