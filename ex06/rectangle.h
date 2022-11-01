#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape{
public:
    // コンストラクタ引数なし
    Rectangle();
    // コンストラクタ引数あり
    explicit Rectangle(Point left_corner, float width, float hight);
    // コピーコンストラクタ
    Rectangle(const Rectangle& Rec_cp);
    // コピーの代入演算子
    Rectangle& operator=(const Rectangle& Rec_cp);

    // 継承メソッド
    string get_name() const override;
    float compute_area() const override;
    Rectangle* create() const override;
    Rectangle* clone() const override;
    ~Rectangle() override;

private:
    Point left_corner;
    float width;
    float height;
};

#endif // RECTANGLE_H