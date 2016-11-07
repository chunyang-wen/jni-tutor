#include <string.h>
#include <ctype.h>

#include "Sample1.h"

static char* strupr(char* p) {
    while(*p) {
        *p = toupper(*p);
        ++p;
    }
    return p;
}

static char* strlwr(char* p) {
    while(*p) {
        *p = tolower(*p);
        ++p;
    }
    return p;
}

/*
 * Class:     Sample1
 * Method:    intMethod
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_Sample1_intMethod
(JNIEnv *env, jobject obj, jint num) {
    return num * num;
}

/*
 * Class:     Sample1
 * Method:    booleanMethod
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_Sample1_booleanMethod
(JNIEnv *env, jobject obj, jboolean boolean) {
    return !boolean;
}

/*
 * Class:     Sample1
 * Method:    stringMethod
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Sample1_stringMethod
(JNIEnv *env, jobject obj, jstring string) {
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    char cap[128];
    strcpy(cap, str);
    (*env)->ReleaseStringUTFChars(env, string, str);
    return (*env)->NewStringUTF(env, strupr(cap));
}

/*
 * Class:     Sample1
 * Method:    intArrayMethod
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_Sample1_intArrayMethod
(JNIEnv *env, jobject obj, jintArray array) {
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for (i = 0; i < len; i++) {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, array, body, 0);
    return sum;
}

int main(int argc, char* argv[]) {
    return 0;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
