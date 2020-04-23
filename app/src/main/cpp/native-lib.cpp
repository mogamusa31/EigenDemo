#include <jni.h>
#include <string>

#include "Eigen/Eigen/Dense"

using namespace Eigen;

extern "C" {
    JNIEXPORT jdouble
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

    JNIEXPORT jfloat JNICALL
    Java_zigzak_net_eigendemo_MainActivity_computeSelfAdjointEigen(JNIEnv *env, jobject thiz) {
        Matrix3f M3;
        M3 << 0,1,2,3,4,5,6,7,8;
        SelfAdjointEigenSolver<Matrix3f> es(M3);
        if(es.info() != Success) abort();
        // 最小の固有値と固有ベクトルの求め方
        auto vec = es.eigenvectors().col(0);
        return es.eigenvalues()(0);
    }

    JNIEXPORT jint JNICALL
    Java_zigzak_net_eigendemo_MainActivity_test(JNIEnv *env, jobject thiz, jobjectArray arr) {
        auto elementCount = env->GetArrayLength(arr);
        if (elementCount == 0) {
            return false;
        }

        printf("%s\n", "test");

        for (auto index = 0; index < elementCount; index++) {
            printf("%i\n", 0);
        }

        return env->GetArrayLength(arr);
    }

    JNIEXPORT jobjectArray JNICALL
    Java_zigzak_net_eigendemo_MainActivity_test2(JNIEnv *env, jobject thiz,
                                                                 jobjectArray arr) {
        return arr;
    }
}