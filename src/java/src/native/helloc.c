#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "br_edu_ifsp_arq_cin_ads_ssi_HelloWorld.h"

// =================== CAESAR ==================================

char *caesar_crypt(char *message, int shift)
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

	m[i] += '\0';
	
	return m;
}

char *caesar_decrypt(char *message, int shift)
{
	char *m = caesar_crypt(message, -shift);

	return m;
}

//=====================================================================

// =================== HILL ===========================================

char *hill_crypt(const char *msg, char *alphabet, int matrix_key[2][2])
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

//=====================================================================

// =========================== OTP ====================================
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
//=====================================================================

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_caesar_1crypt
  (JNIEnv *env, jobject jobj, jstring msg, jint shift)
{
	char *str = (char*) (*env)->GetStringUTFChars(env, msg, NULL);
	
	if (str == NULL)
		return NULL;

	return (*env)->NewStringUTF(env, caesar_crypt(str, shift));
}

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_caesar_1decrypt
  (JNIEnv *env, jobject jobj, jstring msg, jint shift)
{
	char *str = (char*) (*env)->GetStringUTFChars(env, msg, NULL);

	if (str == NULL)
		return NULL;

	return (*env)->NewStringUTF(env, caesar_decrypt(str, shift));
}

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_otp_1crypt
  (JNIEnv * env, jobject jobj, jstring msg, jint shift)
{
	char *str = (char*) (*env)->GetStringUTFChars(env, msg, NULL);

	if (str == NULL)
		return NULL;

	return (*env)->NewStringUTF(env, otp_crypt(str, shift));
}

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_otp_1decrypt
  (JNIEnv * env, jobject jobj, jstring msg, jint shift)
{
	char *str = (char*) (*env)->GetStringUTFChars(env, msg, NULL);

	if (str == NULL)
		return NULL;

	return (*env)->NewStringUTF(env, otp_decrypt(str, shift));
}

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_hill_1crypt
  (JNIEnv *env, jobject jobj, jstring msg, jcharArray jcArray, jobjectArray jobjArray)
{
	int i, j;
	
	int matrix_key[2][2];
	
	char *alphabet = (char*) malloc(sizeof(int)*26);

	char *str = (char*) (*env)->GetStringUTFChars(env, msg, NULL);
	
	jchar *letters;
	jintArray *firstLineOfMatrix;
	jintArray *secondLineOfMatrix;
	jint *arr;
	
	if (str == NULL)
		return NULL;

	letters = (*env)->GetCharArrayElements(env, jcArray, NULL);

	for (i=0; i<26; i++)
	{
		alphabet[i] = letters[i];
	}

	firstLineOfMatrix = (*env)->GetObjectArrayElement(env, jobjArray, 0);
	secondLineOfMatrix = (*env)->GetObjectArrayElement(env, jobjArray, 1);
	
	arr = (*env)->GetIntArrayElements(env, firstLineOfMatrix, NULL);
	matrix_key[0][0] = arr[0];
	matrix_key[0][1] = arr[1];
	arr = (*env)->GetIntArrayElements(env, secondLineOfMatrix, NULL);
	matrix_key[1][0] = arr[0];
	matrix_key[1][1] = arr[1];

	return (*env)->NewStringUTF(env, hill_crypt(str, alphabet, matrix_key));
}