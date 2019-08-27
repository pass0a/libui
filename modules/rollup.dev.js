import resolve from 'rollup-plugin-node-resolve';
import commonjs from 'rollup-plugin-commonjs';
import typescript from 'rollup-plugin-typescript2';

export default [
	// browser-friendly UMD build
	// {
	// 	input: 'src/main.js',
	// 	output: {
	// 		name: 'howLongUntilLunch',
	// 		file: pkg.browser,
	// 		format: 'umd'
	// 	},
	// 	plugins: [
	// 		typescript({ include: [ '*.ts+(|x)', '**/*.ts+(|x)', '*.js+(|x)', '**/*.js+(|x)' ] }),
	// 		resolve(), // so Rollup can find `ms`
	// 		commonjs() // so Rollup can convert `ms` to an ES module
	// 	]
	// },

	// CommonJS (for Node) and ES module (for bundlers) build.
	// (We could have three entries in the configuration array
	// instead of two, but it's quicker to generate multiple
	// builds from a single configuration where possible, using
	// an array for the `output` option, where we can specify
	// `file` and `format` for each target)
	{
		input: 'src/index.ts',
		external: [ 'net', 'stream', 'fs', 'child_process', 'ui.passoa' ],
		plugins: [
			typescript({ include: [ '*.ts+(|x)', '**/*.ts+(|x)', '*.js+(|x)', '**/*.js+(|x)' ] }),
			resolve({ preferBuiltins: true }), // so Rollup can find `ms`
			commonjs() // so Rollup can convert `ms` to an ES module
		],
		output: [ { file: 'dist/index.js', format: 'cjs' } ]
	},
	{
		input: 'test/index.ts',
		external: [ 'net', 'stream', 'fs' ],
		plugins: [
			typescript({ include: [ '*.ts+(|x)', '**/*.ts+(|x)', '*.js+(|x)', '**/*.js+(|x)' ] }),
			resolve({ preferBuiltins: true }), // so Rollup can find `ms`
			commonjs() // so Rollup can convert `ms` to an ES module
		],
		output: [ { file: 'dist/test.js', format: 'cjs' } ]
	}
];
