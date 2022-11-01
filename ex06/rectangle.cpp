#include <stdio.h>
#include <iostream>
#include <string>
#include "rectangle.h"
using namespace std;

// コンストラクタ引数なし
Rectangle::Rectangle(){
    left_corner.x = 0;
    left_corner.y = 0;
    width = 0;
    height = 0;
};

// コンストラクタ引数あり
Rectangle::Rectangle(Point left_corner, float width, float hight){
    this->left_corner = left_corner;
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
Rectangle& Rectangle::operator=(const Rectangle& Rec_cp){
    // 自身の代入チェック
    if (this != &Rec_cp){
        this->left_corner = Rec_cp.left_corner;
        this->width = Rec_cp.width;
        this->height = Rec_cp.height;
    }
    return *this;
}

string Rectangle::get_name()const{
    return "Rectangle";
}

float Rectangle::compute_area()const{
    return this->width * this->height;
}

Rectangle* Rectangle::create()const{
    // 戻り値は（引数無）デフォルトコンストラクタを使って動的メモリに格納されるオブジェクトのポインタ
    // デフォルトコンストラクタを使用する
    Rectangle *Rec_new = new Rectangle();
    return Rec_new;
}

Rectangle* Rectangle::clone()const{
    // 返り値はコピーコンストラクタを使って動的メモリに格納される自分と（全てのメンバ変数の値が）同じオブジェクトのポインタ
    // コピーコンストラクタを使用する
    Rectangle *Rec_clo = new Rectangle(*this);
    return Rec_clo;
}

Rectangle::~Rectangle(){
}