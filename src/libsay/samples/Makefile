CC := gcc
CFLAGS := -c -Wall -Werror -fPIC 
INCLUDES := -I../include
SOURCES := ../src/*.c
OBJECTS := $(SOURCES:.c=.o)
OUT := ../lib/libsay.so

all:
	$(CC) $(OBJECTS) app.c -o app $(INCLUDES)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib ./app 
clean:
	rm -Rf app

