#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

#ifndef DISK_H
#define DISK_H

class Disk : public Shape{
    public:
    // コンストラクタ
    Disk(Point center, float radius);

    // 継承メソッド
    string get_name() override;
    float compute_area() override;
    Disk* create() override;
    Disk* clone() override;
    ~Disk() override;

private:
    Point center;
    float radius;
};

#endif // DISK_H