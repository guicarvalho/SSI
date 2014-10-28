#include <stdio.h>
#include <say.h>
#include <caesar.h>

int main(int argc, char *argv[])
{
	char *nome = "abcdefghijklmnopqrstuvwxyz";

	char *enc_txt = caesar_encrypt(nome, 5);
	char *resp = caesar_decrypt(enc_txt, 5);

	printf("%s", say_print("testing..."));
	printf("%s", say_double(1024));
	printf("[caesar crypt]: %s\n", enc_txt);
	printf("[caesar decrypt]: %s\n", resp);
	
	return 0;
}

