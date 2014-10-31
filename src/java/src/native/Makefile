JDK_PATH := /usr/lib/jvm/java-1.7.0-openjdk-amd64/include

all:
	gcc -o libhelloc.so -shared -fPIC -I../../build/native/include/ -I$(JDK_PATH)/ -I$(JDK_PATH)/linux/ helloc.c -lc

clean:
	rm -Rf libhelloc.so
