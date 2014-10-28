#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <say.h>


#define MAX_STR	256
static char buf[MAX_STR];


static char *produce_string()
{
	char *r = malloc(sizeof(char) * strlen(buf));
	strcpy(r, buf);
	return r;
}


char *say_print(char *msg)
{
	printf("%s\n", msg);
	if (snprintf(buf, MAX_STR, "[libsay]: %s\n", msg) < 0 ) {
		fprintf(stderr, "[libsay]: error producing string\n");
	}

	return produce_string();
}


char *say_double(int x)
{
	if (snprintf(buf, MAX_STR, "[libsay]: %d\n", x * 2) < 0) {
		fprintf(stderr, "[libsay]: error producing string\n");
	}

	return produce_string();
}