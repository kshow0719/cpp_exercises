#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

#ifndef DISK_H
#define DISK_H

class Disk : public Shape{
    public:
    // コンストラクタ
    Disk(Point center, float radius){
        this->center = center;
        this->radius = radius;
    }

    // 継承メソッド
    virtual string get_name();
    virtual float compute_area();
    virtual Disk* create();
    virtual Disk* clone();
    virtual ~Disk(){};

private:
    Point center;
    float radius;
};

#endif // DISK_H