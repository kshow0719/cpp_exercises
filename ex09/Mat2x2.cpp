#include <stdio.h>
#include <iostream>
#include <string>
#include "Mat2x2.h"
using namespace std;

// コンストラクタ引数なし
// 単位行列の作成
template<typename T, int N>
Mat2x2<T, N>::Mat2x2(){
    // 行列の生成
    for (int i = 0; i < N; i++){
        mat[i] = new T[N]; 
    }
    // 単位行列に初期化
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j){
                this->mat[i][j] = 1;
            }
            else{
                this->mat[i][j] = 0;
            }
        }
    }
}

// コンストラクタ引数あり
// NxNの行列の作成
template <typename T, int N>
Mat2x2<T, N>::Mat2x2(T in[]){
    // 行列の生成
    for (int i = 0; i < N; i++){
        mat[i] = new T[N]; 
    }
    // 要素の挿入
    int k = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            this->mat[i][j] = in[k];
            k += N;
        }
        k = 0;
        k = i+1;
    }
}

// overloadメソッド
template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator+(const Mat2x2<T, N>& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2<T, N>();
    // 足し算
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator-(const Mat2x2<T, N>& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2<T, N>();
    // 引き算
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator*(const Mat2x2<T, N>& other){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2<T, N>();
    // 掛け算
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = this->mat[i][j] * other.mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator+=(const Mat2x2<T, N>& other){
    // A = A + B
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *this;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator-=(const Mat2x2<T, N>& other){
    // A = A - B
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *this;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator*=(const Mat2x2<T, N>& other){
    // A = A * B
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->mat[i][j] = this->mat[i][j] * other.mat[i][j];
        }
    }
    return *this;
}

template<typename T, int N>
Mat2x2<T, N>& Mat2x2<T, N>::operator-(){
    // 答えを格納する行列
    Mat2x2 *answer = new Mat2x2<T, N>();
    // B = -A
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = -this->mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
T Mat2x2<T, N>::operator()(int i, int j){
    // 要素を返す
    return this->mat[i][j];
}

template<typename T, int N>
bool Mat2x2<T, N>::operator==(const Mat2x2<T, N>& other){
    // 行列の等価判定
    int TF_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(this->mat[i][j] == other.mat[i][j]){
                TF_count++;
            }
        }
    }
    if(TF_count == N){
        return true;
    }
    else{
        return false;
    }
}

// デストラクタ
template<typename T, int N>
Mat2x2<T, N>::~Mat2x2(){
}

template class Mat2x2<int, 3>;
template std::ostream& operator<<(std::ostream& out, const Mat2x2<int, 3>& other);
template class Mat2x2<double, 2>;
template std::ostream& operator<<(std::ostream& out, const Mat2x2<double ,2>& other);

template<typename T, int N>
ostream& operator<<(ostream& out, const Mat2x2<T, N>& other){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            out << other.mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}