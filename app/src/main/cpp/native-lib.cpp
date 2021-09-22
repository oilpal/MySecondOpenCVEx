#include <jni.h>
#include <string>

#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvex_MainActivity_ConvertRGBtoGray(JNIEnv *env, jobject thiz,
                                                        jlong mat_addr_input,
                                                        jlong mat_addr_result) {
    // TODO: implement ConvertRGBtoGray()

    Mat &matInput = *(Mat *)mat_addr_input;
    Mat &matResult = *(Mat *)mat_addr_result;

    cvtColor(matInput, matResult, COLOR_RGBA2GRAY);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvex_MainActivity_subtraceFrame(JNIEnv *env, jobject thiz,
                                                     jlong mat_addr_old_frame,
                                                     jlong mat_addr_frame,
                                                     jlong mat_addr_sub_frame) {
    // TODO: implement subtraceFrame()

    Mat &matOldFrame = *(Mat *)mat_addr_old_frame;
    Mat &matFrame = *(Mat*)mat_addr_frame;
    Mat &matSubFrame = *(Mat*)mat_addr_sub_frame;

    subtract(matOldFrame, matFrame, matSubFrame);
}