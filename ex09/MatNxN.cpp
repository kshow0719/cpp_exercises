#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include "Mat2x2.h"
using namespace std;

// コンストラクタ引数なし
// 単位行列の作成
template<typename T, int N>
MatNxN<T, N>::MatNxN(){
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
MatNxN<T, N>::MatNxN(T in[]){
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
MatNxN<T, N>& MatNxN<T, N>::operator+(const MatNxN<T, N>& other){
    // 答えを格納する行列
    MatNxN *answer = new MatNxN<T, N>();
    // 足し算
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator-(const MatNxN<T, N>& other){
    // 答えを格納する行列
    MatNxN *answer = new MatNxN<T, N>();
    // 引き算
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator*(const MatNxN<T, N>& other){
    // 答えを格納する行列
    MatNxN *answer = new MatNxN<T, N>();
    // 掛け算
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                answer->mat[i][j] += this->mat[i][k] * other.mat[k][j];
            }
        }
    }
    return *answer;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator+=(const MatNxN<T, N>& other){
    // A = A + B
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->mat[i][j] = this->mat[i][j] + other.mat[i][j];
        }
    }
    return *this;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator-=(const MatNxN<T, N>& other){
    // A = A - B
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->mat[i][j] = this->mat[i][j] - other.mat[i][j];
        }
    }
    return *this;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator*=(const MatNxN<T, N>& other){
    // A = A * B
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                this->mat[i][j] += this->mat[i][k] * other.mat[k][j];
            }
        }
    }
    return *this;
}

template<typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator-(){
    // 答えを格納する行列
    MatNxN *answer = new MatNxN<T, N>();
    // B = -A
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            answer->mat[i][j] = -this->mat[i][j];
        }
    }
    return *answer;
}

template<typename T, int N>
T MatNxN<T, N>::operator()(int i, int j){
    // 要素を返す
    return this->mat[i][j];
}

template<typename T, int N>
bool MatNxN<T, N>::operator==(const MatNxN<T, N>& other){
    // 行列の等価判定
    int TF_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(fabs(this->mat[i][j] - other.mat[i][j]) < 1e-5){
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
MatNxN<T, N>::~MatNxN(){
    for(int i = 0; i < N; i++){
        delete[] mat[i];
    }
    delete mat;
}

template class MatNxN<int, 3>;
template std::ostream& operator<<(std::ostream& out, const MatNxN<int, 3>& other);
template class MatNxN<double, 2>;
template std::ostream& operator<<(std::ostream& out, const MatNxN<double ,2>& other);

template<typename T, int N>
ostream& operator<<(ostream& out, const MatNxN<T, N>& other){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            out << other.mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}