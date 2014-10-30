#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "hill.h"

char* hill_crypt(char *msg, char *alphabet, int matrix_key[2][2])
{
	int i, j, k, sum = 0;
	char *phase = malloc(sizeof(char) * strlen(msg));
	char *ret = malloc(sizeof(char) * strlen(msg));
	for (i = 0; i < strlen(msg); i += 2)
	{
		phase[i] = (msg[i] - 97) % 26;
		phase[i+1] = (msg[i+1] - 97) % 26;
		for (j = 0; j < 2; j++)
		{
			sum = 0;
			for (k = 0; k < 2; k++)
			{
				sum += matrix_key[j][k] * phase[i+k];
			}
			if (j == 0) ret[i] = toupper(alphabet[sum%26]);
			else ret[i+1] = toupper(alphabet[sum%26]);
		}
	}
	return ret;
}
