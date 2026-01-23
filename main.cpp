
#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "NativeSecurity"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_app_NativeLib_getSecretKey(JNIEnv* env, jobject /* this */) {
    // 模拟 JNI 层存储密钥，增加静态分析难度
    // 实际开发中会使用更复杂的混淆
    std::string key = "base64_encoded_secure_key_v2";
    return env->NewStringUTF(key.c_str());
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_app_NativeLib_checkSignature(JNIEnv* env, jobject /* this */, jstring sig) {
    // 模拟原生层签名校验，防止重打包
    const char* nativeSig = env->GetStringUTFChars(sig, 0);
    bool isValid = (std::string(nativeSig) == "expected_hash_value");
    env->ReleaseStringUTFChars(sig, nativeSig);
    return isValid;
}
