#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape{
public:
    // コンストラクタ
    Rectangle(Point left_corner, float width, float hight){
        this->left_center = left_corner;
        this->width = width;
        this->height = hight;
    }

    // 継承メソッド
    virtual string get_name();
    virtual float compute_area();
    virtual Rectangle* create();
    virtual Rectangle* clone();
    virtual ~Rectangle(){};

private:
    Point left_center;
    float width;
    float height;
};

#endif // RECTANGLE_H