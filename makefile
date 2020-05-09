CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/main.o build/board.o build/board_print_plain.o build/board_read.o

.PHONY: clean all bin build default

all: bin build default

default: bin/key

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/main.o 

build/board.o: src/board.c
	$(CXX) $(CFLAGS) src/board.c -o build/board.o

build/board_read.o: src/board_read.c
	$(CXX) $(CFLAGS) src/board_read.c -o build/board_read.o

build/board_print_plain.o: src/board_print_plain.c
	$(CXX) $(CFLAGS) src/board_print_plain.c -o build/board_print_plain.o


build:
	mkdir -p build

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin