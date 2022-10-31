#include <stdio.h>
#include <iostream>
#include "rectangle.h"
using namespace std;

// コンストラクタ
Rectangle::Rectangle(Point left_corner, float width, float hight){
    this->left_center = left_corner;
    this->width = width;
    this->height = hight;
}

// コピーコンストラクタ
Rectangle::Rectangle(const Rectangle& Rec_cp){
    this->left_corner = Rec_cp.left_corner;
    this->width = Rec_cp.width;
    this->height = Rec_cp.height;
}

// コピーの代入演算子
Rectangle::operator=(const Rectangle& Rec_cp){
    // 自身の代入チェック
    if (this != &Rec_cp){
        this->left_corner = Rec_cp.left_corner;
        this->width = Rec_cp.width;
        this->height = Rec_cp.height;
    }
    return *this;
}

Rectangle::get_name(){
    return "Rectangle"
}

Rectangle::compute_area(){
    return this->width * this->height;
}

Rectangle*::create(){
    // 返り値はコンストラクタで受け取った数値をもつRectangleポインタ？
    // デフォルトコンストラクタを使用する
    Rectangle *Rec_new = new Rectangle(this->left_corner, this->width, this->hight);
    return Rec_new;
}

Rectangle*::clone(){
    // 返り値はコンストラクタで受け取った数値をコピーしたRectangleポインタ？
    // コピーコンストラクタを使用する
    Rectangle *Rec_clo = new Rectangle(*this);
}

Rectangle::~Rectangle(){
}