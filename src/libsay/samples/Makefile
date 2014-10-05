all:
	gcc app.c -o app -I../include -L../lib -lsay
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib ./app 

clean:
	rm -Rf app

