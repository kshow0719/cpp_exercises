#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include "disk.h"
using namespace std;

// コンストラクタ引数なし
Disk::Disk(){
    center.x = 0;
    center.y = 0;
    radius = 0;
}

// コンストラクタ引数あり
Disk::Disk(Point center, float radius){
    this->center = center;
    this->radius = radius;
}

// コピーコンストラクタ
Disk::Disk(const Disk& Disk_cp){
    this->center = Disk_cp.center;
    this->radius = Disk_cp.radius;
}

// コピーの代入演算子
Disk& Disk::operator=(const Disk& Disk_cp){
    // 自身の代入チェック
    if(this != &Disk_cp){
        this->center = Disk_cp.center;
        this->radius = Disk_cp.radius;
    }
    return *this;
}

string Disk::get_name()const{
    return "Disk";
}

float Disk::compute_area()const{
    return M_PI * this->radius * this->radius;
}

Disk* Disk::create()const{
    // 返り値は（引数無）デフォルトコンストラクタを使って動的メモリに格納されるオブジェクトのポインタ
    // デフォルトコンストラクタを使用する
    Disk *Disk_new = new Disk();
    return Disk_new;
}

Disk* Disk::clone()const{
    // 返り値はコピーコンストラクタを使って動的メモリに格納される自分と（全てのメンバ変数の値が）同じオブジェクトのポインタ
    // コピーコンストラクタを使用する
    Disk *Disk_clo = new Disk(*this);
    return Disk_clo;
}

Disk::~Disk(){
}