#include <stdio.h>
#include <iostream>
#include <string>
#include "Mat2x2.h"
using namespace std;

// コンストラクタ引数なし
// 単位行列の作成
Mat2x2::Mat2x2(){
    // 行列の生成
    for (int i = 0; i < 2; i++){
        mat[i] = new float[2]; 
    }
    // 単位行列に初期化
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (i == j){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = 0;
            }
        }
    }
}

// コンストラクタ引数あり
// 2x2の行列の作成
Mat2x2::Mat2x2(float in[]){
    // 行列の生成
    for (int i = 0; i < 2; i++){
        mat[i] = new float[2]; 
    }
    // 要素の挿入
    mat[0][0] = in[0];
    mat[1][0] = in[1];
    mat[0][1] = in[2];
    mat[1][1] = in[3];
}

// overloadメソッド
Mat2x2& Mat2x2::operator+(const Mat2x2& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2();
    // 足し算
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            answer->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *answer;
}
Mat2x2& Mat2x2::operator-(const Mat2x2& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2();
    // 引き算
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            answer->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *answer;
}

Mat2x2& Mat2x2::operator*(const Mat2x2& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2();
    // 掛け算
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            answer->mat[i][j] = this->mat[i][j] * other.mat[i][j];
        }
    }
    return *answer;
}

Mat2x2& Mat2x2::operator+=(const Mat2x2& other){
    // A = A + B
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            this->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *this;
}

Mat2x2& Mat2x2::operator-=(const Mat2x2& other){
    // A = A - B
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            this->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *this;
}
Mat2x2& Mat2x2::operator*=(const Mat2x2& other){
    // A = A * B
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            this->mat[i][j] = this->mat[i][j] * other.mat[i][j];
        }
    }
    return *this;
}

Mat2x2& Mat2x2::operator-(){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2();
    // B = -A
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            answer->mat[i][j] = -this->mat[i][j];
        }
    }
    return *answer;
}

float Mat2x2::operator()(int i, int j){
    // 要素を返す
    return this->mat[i][j];
}

bool Mat2x2::operator==(const Mat2x2& other){
    // 行列の等価判定
    int TF_count = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(this->mat[i][j] == other.mat[i][j]){
                TF_count++;
            }
        }
    }
    if(TF_count == 4){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream& out, const Mat2x2& other){
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            out << other.mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

// デストラクタ
Mat2x2::~Mat2x2(){
}