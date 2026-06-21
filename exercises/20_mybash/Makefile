CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
SOURCES := src/mybash/main.c src/myfile/myfile.c src/mysed/mysed.c \
           src/mytrans/mytrans.c src/mytrans/myhash.c src/mywc/mywc.c
OBJECTS := $(patsubst src/%.c,obj/%.o,$(SOURCES))
TARGET := bin/mybash

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf bin obj
