#include <string>
#include <iostream>
using namespace std;

#ifndef MAT2x2_H
#define MAT2x2_H

template <typename T, int N>
class Mat2x2{
private:
    // N次元行列の生成
    // T **mat = new T*[N];
    
public:
    // N次元行列の生成
    T **mat = new T*[N];
    // コンストラクタ引数なし
    // 単位行列の作成
    Mat2x2();
    // コンストラクタ引数あり
    // 2x2の行列の作成
    explicit Mat2x2(T []);

    // overloadメソッド
    Mat2x2& operator+ (const Mat2x2& other);
    Mat2x2& operator- (const Mat2x2& other);

    Mat2x2& operator* (const Mat2x2& other);

    Mat2x2& operator+= (const Mat2x2& other);
    Mat2x2& operator-= (const Mat2x2& other);
    Mat2x2& operator*= (const Mat2x2& other);

    Mat2x2& operator- ();

    T operator() (int i, int j);

    bool operator== (const Mat2x2& other);

    // デストラクタ
    ~Mat2x2();
};

    template<typename T, int N>
    ostream& operator<< (ostream& out, const Mat2x2<T, N>& other);

#endif // MAT2x2_H