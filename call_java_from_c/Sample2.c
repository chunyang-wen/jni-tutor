#include "jni.h"

int main(int argc, char* argv[]) {
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
    long status;
    jclass cls;
    jmethodID mid;
    jint square;
    jboolean not;

    options[0].optionString = "-Djava.class.path=.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = 1;
    vm_args.options = options;
    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    printf("Creating JVM SUC\n");

    if (status != JNI_ERR) {
        cls = (*env)->FindClass(env, "Sample2");
        if ((*env)->ExceptionOccurred(env)) {
            (*env)->ExceptionDescribe(env);
        }
        if (cls != 0) {
            mid = (*env)->GetStaticMethodID(env, cls, "intMethod", "(I)I");
            if (0 != mid) {
                square = (*env)->CallStaticIntMethod(env, cls, mid, 5);
                printf("Result of intMethod: %d\n", square);
            } else {
                printf("Finding intMethod error\n");
            }
            mid = (*env)->GetStaticMethodID(env, cls, "booleanMethod", "(Z)Z");
            if (0 != mid) {
                not = (*env)->CallStaticBooleanMethod(env, cls, mid, 1);
                printf("Result of booleanMethod: %d\n", not);
            } else {
                printf("Finding booleanMethod error\n");
            }
        } else {
            printf("Finding cls error\n");
        }
        (*jvm)->DestroyJavaVM(jvm);
        return 0;
    } else {
        printf("Shit, Error happens\n");
        return -1;
    }
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
