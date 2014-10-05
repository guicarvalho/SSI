JDK_PATH := /usr/lib/jvm/jdk1.8.0_20/include

all:
	gcc -o libhelloc.so -shared -fPIC -I../../build/native/include/ -I$(JDK_PATH)/ -I$(JDK_PATH)/linux/ helloc.c -lc

clean:
	rm -Rf libhelloc.so
