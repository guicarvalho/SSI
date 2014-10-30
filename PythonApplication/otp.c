#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "otp.h"

char *otp_decrypt(char *str, int key)
{
	int i;
	int len = strlen(str);
	char *decrypted_text = (char*) malloc(sizeof(char) * len);
	srand(key);
	for (i = 0; i < len; ++i)
		decrypted_text[i] = str[i] - (random()%256)%256;
	return decrypted_text;
}

char *otp_crypt(char *str, int key)
{
	int i;
	int len = strlen(str);
	char *crypted_text = (char*) malloc(sizeof(char) * len);
	srand(key);
	for (i = 0; i < len; ++i)
		crypted_text[i] = str[i] + (random()%256)%256;
	return crypted_text;
}
