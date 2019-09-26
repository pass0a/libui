import * as bind from './binding';
export default class uiControl extends bind.uiEvent {
	show(): void {
		bind.controlOp(this.handle, 0);
	}
	hide(): void {
		bind.controlOp(this.handle, 1);
	}
	enable(): void {
		bind.controlOp(this.handle, 2);
	}
	disable(): void {
		bind.controlOp(this.handle, 3);
	}
	isVisable(): boolean {
		return bind.controlOp(this.handle, 5);
	}
	isEnable(): boolean {
		return bind.controlOp(this.handle, 6);
	}
	topLevel(): number {
		return bind.controlOp(this.handle, 7);
	}
	parent(): any {
		let handle = bind.controlOp(this.handle, 8);
		console.log('parent', handle);
		if (bind.uiEvent.map.has(handle)) {
			return bind.uiEvent.map.get(handle);
		}
	}
}
