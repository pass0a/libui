import uiControl from './uiControl';
import * as bind from './binding';
export class uiWindow extends uiControl {
	constructor(title: string, width: number, heigth: number, isMember: number) {
		super(bind.newWindow(title, width, heigth, isMember));
		console.log(this.handle);
		this.on('close', () => {
			console.log('closing');
		});
	}
	show() {
		bind.controlShow(this.handle);
	}
	close() {}
	setMargined(margined: boolean) {}
	getMargined(): boolean {
		return true;
	}
	setChild(control: uiControl) {
		bind.windowSetChild(this.handle, control.handle);
	}
	setTitle(title: string) {}
	getTitle(): string {
		return '';
	}
	getFullscreen(): boolean {
		return false;
	}
	setFullscreen(value: boolean) {}
	getBorderless(): boolean {
		return true;
	}
	setBorderless(value: boolean) {}
	getContentSize(): number {
		return 1;
	}
	setContentSize(value: number) {}
}
