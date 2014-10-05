#include <stdio.h>
#include <say.h>

int main(int argc, char *argv[])
{
	printf("%s", say_print("testing..."));
	printf("%s", say_double(1024));
	return 0;
}

