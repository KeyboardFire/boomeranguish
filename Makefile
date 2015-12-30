OBJECTS = $(patsubst src/%.c, bin/%.o, $(wildcard src/*.c))
HEADERS = $(wildcard src/*.h)

.PHONY: all clean

all: bin/boomeranguish

bin/%.o: src/%.c $(HEADERS)
	gcc -O3 -Wall -Wpedantic -Wextra -c $< -o $@ -std=c99

bin/boomeranguish: $(OBJECTS)
	gcc -O3 -Wall -Wpedantic -Wextra $^ -o $@ -std=c99

clean:
	-rm -f bin/*
