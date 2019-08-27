import * as libui from '../src/index';
import { readdirSync } from 'fs';
import { extname } from 'path';
import { execSync } from 'child_process';
let handle = [ '.mp3', '.mp4', '.mkv' ];
libui.init();
let input = libui.openFolder();
let list = readdirSync(input);
for (const iterator of list) {
	if (handle.indexOf(extname(iterator)) > 0) {
		execSync;
	}
}
