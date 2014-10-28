CC := gcc
CFLAGS := -c -Wall -Werror -fPIC 
INCLUDES := -I../include
SOURCES := *.c
OBJECTS := $(SOURCES:.c=.o)
OUT := ../lib/libsay.so

#.SUFFICES: .c

all: $(OUT)

$(OUT): $(OBJECTS) say

say:
	@echo "Generating ../lib/libsay.so"
	$(CC) -o $(OUT) -shared $(OBJECTS)
.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(OUT) 

