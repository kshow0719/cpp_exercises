#include <string>
#include <iostream>
#include"shape.h"
using namespace std;

#ifndef POLYGON_H
#define POLYGON_H

class Polygon : public Shape{
public:
    // コンストラクタ引数なし
    Polygon();
    // コンストラクタ引数あり
    explicit Polygon(int vertex_num, Point Vertex[]);
    // コピーコンストラクタ
    Polygon(const Polygon& polygon_cp);
    // コピーの代入演算子
    Polygon& operator=(const Polygon& polygon_cp);
    
    // 継承メソッド
    string get_name() const override;
    float compute_area() const override;
    Polygon* create() const override;
    Polygon* clone() const override;
    ~Polygon() override;

private:
    int vertex_num;
    Point *vertex;
}

#endif // POLYGON_H