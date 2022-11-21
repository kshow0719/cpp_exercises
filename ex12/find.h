#include <cmath>
#include <vector>
#include <queue>

#ifndef FIND_H
#define FIND_H

// Point構造体
struct Point {
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

// Compare関数オブジェクト
class Compere
{
private:
    /* data */
public:
    Compere();
    ~Compere();
};

/// 関数 find_k_closest()
void find_k_closest(){}

#endif // FIND_H