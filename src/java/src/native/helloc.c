#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "caesar.h"
#include "br_edu_ifsp_arq_cin_ads_ssi_HelloWorld.h"


JNIEXPORT void JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_helloFromC
  (JNIEnv *env, jobject jobj)
{
	printf("Hello world from C!\n");
}

JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_crypt
  (JNIEnv *env, jobject jobj, jstring msg)
{
	const jbyte *m;
	char *str = malloc(sizeof(char) * 10);

	if (!(m = (*env)->GetStringUTFChars(env, msg, NULL))) {
		return NULL;
	}
	printf("[C]: message: %s\n", m);

	str = "123456789";
	return (*env)->NewStringUTF(env, str);
}


const char *test_1(const char *name) {
	return name;
}

/* Caesar cipher */
JNIEXPORT jstring JNICALL Java_br_edu_ifsp_arq_cin_ads_ssi_HelloWorld_caesar_1crypt
  (JNIEnv *env, jobject jobj, jstring msg, jint shift)
{
	const char *str = (*env)->GetStringChars(env, msg, 0);
	
	if (str == NULL)
		return NULL;
	
	// funciona (função defina aqui dentro)
	const char *resp_1 = test_1((const char *)"olá mundo");
	printf("resposta(1) da função: %s\n", resp_1);
	
	// não funciona (função externa)
	(*env)->ReleaseStringChars(env, msg, str);
	const char *resp_2 = test(str);
	printf("resposta(2) da função: %s\n", resp_2);

	return (*env)->NewStringUTF(env, str);
}
/* ============= */
