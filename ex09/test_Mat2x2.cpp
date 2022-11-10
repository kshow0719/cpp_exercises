#include <stdio.h>
#include <iostream>
#include <string>
#include "Mat2x2.h"
using namespace std;

int main(void){
    // ex9 テスト
    cout << "---------------- Test for int Mat3x3 ----------------" << endl;
    
    // 行列の要素を格納するfloat[]
    int in1[] = {3, 4, 5};
    int in2[] = {1, 3, 6};

    // 単位行列の生成
    Mat2x2<int, 3> mat0 = Mat2x2<int, 3>();
    cout << " mat0 =\n" << mat0;

    // 各演算の結果を格納する
    Mat2x2<int, 3> mat_result_i = Mat2x2<int, 3>();
    int result_i;

    // 2x2行列の作成
    Mat2x2<int, 3> mat1 = Mat2x2<int, 3>(in1);
    cout << " mat1 =\n" << mat1;
    Mat2x2<int, 3> mat2 = Mat2x2<int, 3>(in2);
    cout << " mat2 =\n" << mat2;

    // overloadメソッド テスト
    // 加算
    mat_result_i = mat1 + mat2;
    cout << " mat_add =\n" << mat_result_i<int, 3>;

    // 減算
    mat_result_i = mat1 - mat2;
    cout << " mat_sub =\n" << mat_result_i<int, 3>;

    // 乗算
    mat_result_i = mat1 * mat2;
    cout << " mat_mult =\n" << mat_result_i<int, 3>;

    // 複合加算
    mat_result_i = mat1 += mat2;
    cout << " mat_compound_add =\n" << mat_result_i<int, 3>;

    // 複合減算
    mat_result_i = mat1 -= mat2;
    cout << " mat_compound_sub =\n" << mat_result_i<int, 3>;

    // 複合乗算
    mat_result_i = mat1 *= mat2;
    cout << " mat_compound_mult =\n" << mat_result_i<int, 3>;

    // 単項マイナス
    mat_result_i = -mat1;
    cout << " mat_compound_mult =\n" << mat_result_i<int, 3>;
    cout << " mat_unary_minus =\n" << mat_result_i<int, 3>;

    // 要素の取得
    result_i = mat1(0, 0);
    cout << " mat1[0][0] = \n" << result_i << endl;

    // 等価判定
    if(mat1 == mat2){
        cout << " mat1 & mat2 is equal." << endl;
    }
    else{
        cout << " mat1 & mat2 is not equal." << endl;
    }


    // ex9 テスト
    cout << "---------------- Test for doublle Mat5x5 ----------------" << endl;
    
    // 行列の要素を格納するdouble[]
    double in3[] = {3.0, 4.2, 5.0, 8.3, 1.6};
    double in4[] = {1.1, 3.0, 6.5, 10.2, 2.7};

    // 各演算の結果を格納する
    Mat2x2<double, 5> mat_result_d = Mat2x2<double, 5>();
    double result_d;

    // 5x5行列の作成
    Mat2x2<double, 5> mat3 = Mat2x2<double, 5>(in3);
    cout << " mat1 =\n" << mat3;
    Mat2x2<double, 5> mat4 = Mat2x2<double, 5>(in4);
    cout << " mat2 =\n" << mat4;

    // overloadメソッド テスト
    // 加算
    mat_result_d = mat3 + mat4;
    cout << " mat_add =\n" << mat_result_d;

    // 減算
    mat_result_d = mat3 - mat4;
    cout << " mat_sub =\n" << mat_result_d;

    // 乗算
    mat_result_d = mat3 * mat4;
    cout << " mat_mult =\n" << mat_result_d;

    // 複合加算
    mat_result_d = mat3 += mat4;
    cout << " mat_compound_add =\n" << mat_result_d;

    // 複合減算
    mat_result_d = mat3 -= mat4;
    cout << " mat_compound_sub =\n" << mat_result_d;

    // 複合乗算
    mat_result_d = mat3 *= mat4;
    cout << " mat_compound_mult =\n" << mat_result_d;

    // 単項マイナス
    mat_result_d = -mat3;
    cout << " mat_unary_minus =\n" << mat_result_d;

    // 要素の取得
    result_d = mat3(0, 0);
    cout << " mat1[0][0] = \n" << result_d << endl;

    // 等価判定
    if(mat3 == mat4){
        cout << " mat3 & mat4 is equal." << endl;
    }
    else{
        cout << " mat3 & mat4 is not equal." << endl;
    }

    return 0;
}