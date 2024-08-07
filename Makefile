bad_example/index.html: src/bad_example.c
	mkdir -p bad_example
	emcc src/bad_example.c -o bad_example/index.html -s WASM=1
