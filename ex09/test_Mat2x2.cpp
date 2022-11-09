#include <stdio.h>
#include <iostream>
#include <string>
#include "Mat2x2.h"
using namespace std;

int main(void){
    // ex8 テスト
    cout << "---------------- Test for Mat2x2 ----------------" << endl;
    
    // 行列の要素を格納するfloat[]
    float in_result[] = {0, 0, 0, 0};
    float in1[] = {3, 4, 5, 8};
    float in2[] = {1, 3, 6, 10};

    // 単位行列の生成
    Mat2x2 mat0();

    // 各演算の結果を格納する
    Mat2x2 mat_result(in_result);
    float result;

    // 2x2行列の作成
    Mat2x2 mat1(in1);
    cout << " mat1 =\n" << mat1;
    Mat2x2 mat2(in2);
    cout << " mat2 =\n" << mat2;

    // overloadメソッド テスト
    // 加算
    mat_result = mat1 + mat2;
    cout << " mat_add =\n" << mat_result;

    // 減算
    mat_result = mat1 - mat2;
    cout << " mat_sub =\n" << mat_result;

    // 乗算
    mat_result = mat1 * mat2;
    cout << " mat_mult =\n" << mat_result;

    // 複合加算
    mat_result = mat1 += mat2;
    cout << " mat_compound_add =\n" << mat_result;

    // 複合減算
    mat_result = mat1 -= mat2;
    cout << " mat_compound_sub =\n" << mat_result;

    // 複合乗算
    mat_result = mat1 *= mat2;
    cout << " mat_compound_mult =\n" << mat_result;

    // 単項マイナス
    mat_result = -mat1;
    cout << " mat_unary_minus =\n" << mat_result;

    // 要素の取得
    result = mat1(0, 0);
    cout << " mat1[0][0] = \n" << result << endl;

    // 等価判定
    if(mat1 == mat2){
        cout << " mat1 & mat2 is equal." << endl;
    }
    else{
        cout << " mat1 & mat2 is not equal." << endl;
    }

    return 0;
}