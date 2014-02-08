all:
	../emscripten/em++ src/Main.cpp -s ASM_JS=1 -O2 -o index.html
