CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/src/main.o build/src/board.o build/src/board_print_plain.o build/src/board_read.o


OBJECTS_TEST = build/test/main.o build/test/tests.o build/src/board.o build/src/board_read.o build/src/board_print_plain.o

.PHONY: clean all bin build default

all: bin build default test

default: bin/key

test: bin build bin/key_test
	bin/key_test

bin/key_test: $(OBJECTS_TEST)
	$(CXX) $(FLAGS) $(OBJECTS_TEST) -o bin/key_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o 

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o 

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/src/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o 

build/src/board.o: src/board.c
	$(CXX) $(CFLAGS) src/board.c -o build/src/board.o

build/src/board_read.o: src/board_read.c
	$(CXX) $(CFLAGS) src/board_read.c -o build/src/board_read.o

build/src/board_print_plain.o: src/board_print_plain.c
	$(CXX) $(CFLAGS) src/board_print_plain.c -o build/src/board_print_plain.o


build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin