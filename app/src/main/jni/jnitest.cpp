#include <jni.h>
#include "com.jushenziao.admin.jnidemo.h"
/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getJNIString
 * Signature: ()Ljava/lang/String;
 */
//JNIEXPORT jstring JNICALL Java_com_jushenziao_admin_jnidemo_MainActivity_getCLanguageString(JNIEnv *env, jobject obj){
//     return env->NewStringUTF("This just a test for Android Studio NDK JNI developer!");
//  }
#define NULL 0

jstring native_hello(JNIEnv* env, jobject thiz)
{
    return env->NewStringUTF("来自JNI的字符串");
}

static JNINativeMethod gMethods[] = {
        {"getJNIString", "()Ljava/lang/String;", (void*)native_hello},//绑定
};
/*
* 为某一个类注册本地方法
*/
static int registerNativeMethods(JNIEnv* env
        , const char* className
        , JNINativeMethod* gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives( clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}


/*
* 为所有类注册本地方法
*/
static int registerNatives(JNIEnv* env) {
    const char* kClassName = "com/srv/HelloWorld";//指定要注册的类
    return registerNativeMethods(env, kClassName, gMethods,
                                 sizeof(gMethods) / sizeof(gMethods[0]));
}

/*
* System.loadLibrary("lib")时调用
* 如果成功返回JNI版本, 失败返回-1
*/
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    if (!registerNatives(env)) {//注册
        return -1;
    }
    //成功
    result = JNI_VERSION_1_4;

    return result;
}