#include "Cal.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_editTextFromJNI(JNIEnv *env, jobject thiz,
                                                            jstring str) {
    // TODO: implement editTextFromJNI()
    //const char *ceremony=env->GetStringUTFChars(str);
    //string ce=ceremony;
    jboolean isCopy;
    string arr=env->GetStringUTFChars(str,&isCopy); //string 받아들이기
    Cal cal;

    //생성자 소멸자에서 자동 메모리해제 안드환경에서 테스트함해보자
    cal.Cal_Set(arr);
    cal.Cal_Str(); //문자열변환
    cal.Calc(); //계산

    //cal.Cal_Print(); //프린트
    string value=cal.Cal_return();
    return env->NewStringUTF(value.c_str());
}


