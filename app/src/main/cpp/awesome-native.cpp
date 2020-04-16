//
// Created by Daiwei Lu on 4/15/20.
//

#include "awesome-native.h"

#include <android/log.h>
#include <jni.h>
//#include <base/logging.h>

extern "C"
void sayHello(JNIEnv *jni, jobject obj) {
    __android_log_print(ANDROID_LOG_DEBUG, "awesome-native", "hello");
    jclass jClassAwesomeNative = jni->GetObjectClass(obj);
    jmethodID jMethodIDSayGoodBye = jni->GetMethodID(jClassAwesomeNative, "sayGoodBye", "()V");
    jni->CallVoidMethod(obj, jMethodIDSayGoodBye);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    // Find your class. JNI_OnLoad is called from the correct class loader context for this to work.
    jclass c = env->FindClass("com/daiwei/learnndkbuild/AwesomeNative");
    if (c == nullptr) {
        return JNI_ERR;
    }

    // Register your class' native methods.
    static const JNINativeMethod methods[] = {
        {"sayHello", "()V", reinterpret_cast<void*>(sayHello)},
        // {"nativeBar", "(Ljava/lang/String;I)Z", reinterpret_cast<void*>(nativeBar)},
    };
    int rc = env->RegisterNatives(c, methods, sizeof(methods)/sizeof(JNINativeMethod));
    if (rc != JNI_OK) {
        return rc;
    }

    return JNI_VERSION_1_6;
}
