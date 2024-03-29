#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#ifndef MATNxN_H
#define MATNxN_H

template <typename T, int N>
class MatNxN{
private:
    // N次元行列の生成
    // T **mat = new T*[N];
    
public:
    // N次元行列の生成
    T **mat = new T*[N];
    // コンストラクタ引数なし
    // 単位行列の作成
    MatNxN(){
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
    };
    // コンストラクタ引数あり
    // NxNの行列の作成
    explicit MatNxN(T in[]){
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
    };

    // overloadメソッド
    MatNxN<T, N>& operator+ (const MatNxN<T, N>& other){
        // 答えを格納する行列
        MatNxN *answer = new MatNxN<T, N>();
        // 足し算
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                answer->mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return *answer;
    };
    MatNxN<T, N>& operator- (const MatNxN<T, N>& other){
        // 答えを格納する行列
        MatNxN *answer = new MatNxN<T, N>();
        // 引き算
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                answer->mat[i][j] = this->mat[i][j] - other.mat[i][j];
            }
        }
        return *answer;
    };

    MatNxN<T, N>& operator* (const MatNxN<T, N>& other){
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
    };

    MatNxN<T, N>& operator+= (const MatNxN<T, N>& other){
        // A = A + B
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                this->mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return *this;
    };
    MatNxN<T, N>& operator-= (const MatNxN<T, N>& other){
        // A = A - B
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                this->mat[i][j] = this->mat[i][j] - other.mat[i][j];
            }
        }
        return *this;
    };
    MatNxN<T, N>& operator*= (const MatNxN<T, N>& other){
        // A = A * B
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    this->mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return *this;
    };

    MatNxN<T, N>& operator- (){
        // 答えを格納する行列
        MatNxN *answer = new MatNxN<T, N>();
        // B = -A
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                answer->mat[i][j] = -this->mat[i][j];
            }
        }
        return *answer;
    };

    // T operator() (int i, int j);
    // 追加
    T& operator()(int i, int j){
        // 要素を返す
        return this->mat[i][j];
    };
    const T& operator()(int i, int j) const{
        // 要素を返す
        return this->mat[i][j];
    };

    bool operator== (const MatNxN<T, N>& other){
        // 行列の等価判定
        int TF_count = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(fabs(this->mat[i][j] - other.mat[i][j]) < 1e-5){
                    TF_count++;
                }
            }
        }
        if(TF_count == N*N){
            return true;
        }
        else{
            return false;
        }
    };

    // デストラクタ
    ~MatNxN(){
        for(int i = 0; i < N; i++){
            delete[] mat[i];
        }
        delete mat;
    };
};

template<typename T, int N>
ostream& operator<< (ostream& out, const MatNxN<T, N>& other){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            out << other.mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

#endif // MATNxN_H