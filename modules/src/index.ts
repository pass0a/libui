if ('win32' == process.platform) {
	process.env.Path = process.env.Path + ';' + __dirname;
} else {
	process.env.Path = process.env.Path;
}
var ui = require('./ui.passoa');
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
	return ui.init();
}
