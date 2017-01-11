/* 
 * File:   jni_config.hpp
 * Author: alex
 *
 * Created on January 10, 2017, 9:48 PM
 */

#ifndef WILTON_JNI_WILTON_JNI_CONFIG_HPP
#define	WILTON_JNI_WILTON_JNI_CONFIG_HPP

// helper macros
#define WILTON_QUOTE(value) #value
#define WILTON_STR(value) WILTON_QUOTE(value)
#define WILTON_PASTER(x,y) Java_ ## x ## _ ## y
#define WILTON_EVALUATOR(x,y) WILTON_PASTER(x,y)
#define WILTON_JNI_FUNCTION(fun) WILTON_EVALUATOR(WILTON_JNI_CLASS_NAME, fun)

// JNI version
#ifndef WILTON_JNI_VERSION
#define WILTON_JNI_VERSION JNI_VERSION_1_6
#endif // WILTON_JNI_VERSION

// name of the Java class that will expose `wiltoncall` method
// and will provide static methods used below
#ifndef WILTON_JNI_CLASS_NAME
#define WILTON_JNI_CLASS_NAME net_wiltonwebtoolkit_WiltonJni
#endif // WILTON_JNI_CLASS_NAME

// signature of the same Java class above
#ifndef WILTON_JNI_CLASS_SIGNATURE
#define WILTON_JNI_CLASS_SIGNATURE net/wiltonwebtoolkit/WiltonJni
#endif // WILTON_JNI_CLASS_SIGNATURE
#define WILTON_JNI_CLASS_SIGNATURE_STR WILTON_STR(WILTON_JNI_CLASS_SIGNATURE)

// static method that runs specified script
#ifndef WILTON_JNI_RUNSCRIPT_METHOD
#define WILTON_JNI_RUNSCRIPT_METHOD runScript
#endif // WILTON_JNI_RUNSCRIPT_METHOD
#define WILTON_JNI_RUNSCRIPT_METHOD_STR WILTON_STR(WILTON_JNI_RUNSCRIPT_METHOD)
#define WILTON_JNI_RUNSCRIPT_METHOD_SIGNATURE (Ljava/lang/String;)Ljava/lang/String;
#define WILTON_JNI_RUNSCRIPT_METHOD_SIGNATURE_STR WILTON_STR(WILTON_JNI_RUNSCRIPT_METHOD_SIGNATURE)

// static method that throws exception with specified message
#ifndef WILTON_JNI_THROWEXCEPTION_METHOD
#define WILTON_JNI_THROWEXCEPTION_METHOD throwException
#endif // WILTON_JNI_THROWEXCEPTION_METHOD
#define WILTON_JNI_THROWEXCEPTION_METHOD_STR WILTON_STR(WILTON_JNI_THROWEXCEPTION_METHOD)
#define WILTON_JNI_THROWEXCEPTION_METHOD_SIGNATURE (Ljava/lang/String;)V
#define WILTON_JNI_THROWEXCEPTION_METHOD_SIGNATURE_STR WILTON_STR(WILTON_JNI_THROWEXCEPTION_METHOD_SIGNATURE)

// static method that returns specified exception details as a string
#ifndef WILTON_JNI_DESCRIBEEXCEPTION_METHOD
#define WILTON_JNI_DESCRIBEEXCEPTION_METHOD describeException
#endif // WILTON_JNI_DESCRIBEEXCEPTION_METHOD
#define WILTON_JNI_DESCRIBEEXCEPTION_METHOD_STR WILTON_STR(WILTON_JNI_DESCRIBEEXCEPTION_METHOD)
#define WILTON_JNI_DESCRIBEEXCEPTION_METHOD_SIGNATURE (Ljava/lang/Throwable;)Ljava/lang/String;
#define WILTON_JNI_DESCRIBEEXCEPTION_METHOD_SIGNATURE_STR WILTON_STR(WILTON_JNI_DESCRIBEEXCEPTION_METHOD_SIGNATURE)

// directory to dump startup errors into
#ifndef WILTON_STARTUP_ERR_DIR
#define WILTON_STARTUP_ERR_DIR
#endif // WILTON_STARTUP_ERR_DIR
#define WILTON_STARTUP_ERR_DIR_STR WILTON_STR(WILTON_STARTUP_ERR_DIR)


#endif	/* WILTON_JNI_WILTON_JNI_CONFIG_HPP */