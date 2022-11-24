#include <string>
#include <iostream>
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
    MatNxN();
    // コンストラクタ引数あり
    // 2x2の行列の作成
    explicit MatNxN(T []);

    // overloadメソッド
    MatNxN& operator+ (const MatNxN& other);
    MatNxN& operator- (const MatNxN& other);

    MatNxN& operator* (const MatNxN& other);

    MatNxN& operator+= (const MatNxN& other);
    MatNxN& operator-= (const MatNxN& other);
    MatNxN& operator*= (const MatNxN& other);

    MatNxN& operator- ();

    // T operator() (int i, int j);
    // 追加
    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;

    bool operator== (const MatNxN& other);

    // デストラクタ
    ~MatNxN();
};

    template<typename T, int N>
    ostream& operator<< (ostream& out, const MatNxN<T, N>& other);

#endif // MATNxN_H