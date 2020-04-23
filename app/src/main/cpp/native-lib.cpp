#include <jni.h>
#include <string>

#include "Eigen/Eigen/Dense"

using Eigen::MatrixXd;

extern "C" JNIEXPORT jdouble
JNICALL
Java_zigzak_net_eigendemo_MainActivity_computeDeterminant(
        JNIEnv *env,
        jobject /* this */) {

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);

    return m.determinant();
}