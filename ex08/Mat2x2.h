#include <string>
#include <iostream>
using namespace std;

#ifndef MAT2x2_H
#define MAT2x2_H

class Mat2x2{
private:
    /* data */
public:
    // コンストラクタ引数なし
    // 単位行列の作成
    Mat2x2();
    // コンストラクタ引数あり
    // 2x2の行列の作成
    explicit Mat2x2(float[]);

    // overloadメソッド
    Mat2x2& operator+ (const Mat2x2& other);
    Mat2x2& operator- (const Mat2x2& other);

    Mat2x2& operator* (const Mat2x2& other);

    Mat2x2& operator+= (const Mat2x2& other);
    Mat2x2& operator-= (const Mat2x2& other);
    Mat2x2& operator*= (const Mat2x2& other);

    Mat2x2& operator- ();

    float operator() (int i, int j);

    bool operator== (const Mat2x2& other);

    ostream& operator<< (std::ostream &out, const Mat2x2& other);

    // デストラクタ
    ~Mat2x2();
};

#endif // MAT2x2_H