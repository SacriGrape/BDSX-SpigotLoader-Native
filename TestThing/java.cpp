#include <jni.h>       /* where everything is defined */

void initJavaStuff() {
	JavaVM* jvm;       /* denotes a Java VM */
	JNIEnv* env;       /* pointer to native method interface */
	JavaVMInitArgs vm_args; /* JDK/JRE 10 VM initialization arguments */

	JavaVMOption* options = new JavaVMOption[1];
	options[0].optionString = (char*)"-Djava.class.path=/usr/lib/java";
}