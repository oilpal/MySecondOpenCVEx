#include <jni.h>
#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

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

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvex_MainActivity_subtractBG(JNIEnv *env, jobject thiz,
                                                  jlong mat_addr_bg_frame_binary,
                                                  jlong mat_addr_frame, jlong mat_addr_sub_frame) {
    // TODO: implement subtraceBG()

    Mat &matBgFrameBinary = *(Mat*)mat_addr_bg_frame_binary;
    Mat &matFrame = *(Mat*)mat_addr_frame;
    Mat matFrameBinary;
    Mat &matSubFrame = *(Mat*)mat_addr_sub_frame;

    cvtColor(matFrame, matFrameBinary, COLOR_BGR2GRAY);

    absdiff(matBgFrameBinary, matFrameBinary, matSubFrame);

    // 차이값이 70 이상인 것만 255(흰색)으로 이진화 시켜라라는 뜻.
    threshold(matSubFrame, matSubFrame, 70, 255, THRESH_BINARY);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvex_MainActivity_convertColorToGray(JNIEnv *env, jobject thiz,
                                                          jlong mat_frame, jlong mat_frame_binary) {
    // TODO: implement convertColorToGray()

    Mat &matFrame = *(Mat*)mat_frame;
    Mat &matFrameBinary = *(Mat*)mat_frame_binary;

    cvtColor(matFrame, matFrameBinary, COLOR_BGR2GRAY);
}

void draw_rect(Mat& img, vector<Rect>& v_rect) {
    for(auto it : v_rect) {
        rectangle(img, it, CV_RGB(0, 0, 255), 2);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvex_MainActivity_drawContours(JNIEnv *env, jobject thiz,
                                                    jlong mat_addr_bg_frame_binary,
                                                    jlong mat_addr_frame,
                                                    jlong mat_addr_sub_frame) {
    // TODO: implement drawContours()

    Mat &matBgFrameBinary = *(Mat*)mat_addr_bg_frame_binary;
    Mat &matFrame = *(Mat*)mat_addr_frame;
    Mat matFrameBinary;
    Mat &matSubFrame = *(Mat*)mat_addr_sub_frame;

    cvtColor(matFrame, matFrameBinary, COLOR_BGR2GRAY);

    absdiff(matBgFrameBinary, matFrameBinary, matSubFrame);

    // 차이값이 70 이상인 것만 255(흰색)으로 이진화 시켜라라는 뜻.
    threshold(matSubFrame, matSubFrame, 70, 255, THRESH_BINARY);

    // find contour
    std::vector< std::vector<Point>> contours;
    std::vector< Vec4i> hierarchy;
    findContours(matSubFrame.clone(), contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    //drawContours(matFrame, contours, -1, CV_RGB(255, 0, 0), 5, 8, hierarchy);

    // Blob labeling
    vector< Rect > v_rect;
    for(auto it : contours) {
        Rect mr = boundingRect(Mat(it));
        v_rect.push_back(mr);
    }
    draw_rect(matFrame, v_rect);
}