#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <caesar.h>


char * caesar_encrypt(char *message, int shift)
{
	int i;
	char *m = (char *) malloc(sizeof(char) * strlen(message)); 
	char offset = 'a';

	for (i = 0; i < strlen(message); i++)
	{
		m[i] = message[i] | 32;
		m[i] -= offset;
		m[i] += shift;
		m[i] = m[i] % 26;
		m[i] = (m[i] < 0)? m[i] + 26 : m[i];
		m[i] += offset;
	}

	return m;
}

char * caesar_decrypt(char *message, int shift)
{
	char *m = caesar_encrypt(message, -shift);

	return m;
}