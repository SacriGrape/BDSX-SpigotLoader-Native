#include <windows.h>
#include <iostream>

#include "java.h"

void initJava()
{
	SetDllDirectoryA("../SpigotLoader/jre/bin");

	JavaVM* jvm;
	JNIEnv* env;
	JavaVMInitArgs vm_args;

	vm_args.version = JNI_VERSION_10;
	vm_args.nOptions = 0;
	vm_args.ignoreUnrecognized = false;
	JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
	
	jclass urlClass = env->FindClass("java/net/URL");
	jmethodID urlConstructor = env->GetMethodID(urlClass, "<init>", "(Ljava/lang/String;)Ljava/net/URL;");
	jobject URL = env->NewObject(urlClass, urlConstructor, env->NewStringUTF("https://google.com"));
}