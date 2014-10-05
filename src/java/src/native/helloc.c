#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
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


