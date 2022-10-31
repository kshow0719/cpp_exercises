#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "disk.h"
using namespace std;

// コンストラクタ
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
Disk::operator=(const Disk& Disk_cp){
    // 自身の代入チェック
    if(this != &Disk_cp){
        this->center = Disk_cp.center;
        this->radius = Disk_cp.radius;
    }
    return *this;
}

Disk::get_name(){
    return "Disk"
}

Disk::compute_area(){
    return M_PI * this->radius * this->radius;
}

Disk*::create(){
    // 返り値はコンストラクタで受け取った数値をもつDiskポインタ？
    // デフォルトコンストラクタを使用する
    Disk *Disk_new = new Disk(this->center, this->radius);
    return Disk_new;
}

Disk*::clone(){
    // 返り値はコンストラクタで受け取った数値をコピーしたDiskポインタ？
    // コピーコンストラクタを使用する
    Disk *Disk_clo = new Disk(*this);
}

Disk::~Disk(){
}