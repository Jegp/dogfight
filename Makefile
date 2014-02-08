CC=../emscripten/em++
CC_FLAGS=
LD_FLAGS=ASM_JS=1
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE=index.html
SRCDIR=src/

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LD_FLAGS) -O2 -o $@ $^

obj/$.o: src/%.cpp
	$(CC) -s $(CC_FLAGS) -O2 -c -o $@ $<

clean:
	rm -rf obj/*
