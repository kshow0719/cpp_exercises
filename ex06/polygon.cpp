#include <stdio.h>
#include <string>
#include <iostream>
#include"polygon.h"
using namespace std;

// コンストラクタ引数なし
Polygon::Polygon(){
    vertex_num = 0;
    vertex = nullptr;
}

// コンストラクタ引数あり
Polygon::Polygon(int vertex_num, Point Vertex[]){
    this->vertex_num = vertex_num;
    this->vertex = new Point[this->vertex_num];
    for(int i = 0; i < this-> vertex_num; i++){
        this->vertex[i].x = Vertex[i].x;
        this->vertex[i].y = Vertex[i].y;
    }
}

// コピーコンストラクタ
Polygon::Polygon(const Polygon& polygon_cp){
    this->vertex_num = polygon_cp.vertex_num;
    this->vertex = new Point[polygon_cp.vertex_num];
    for(int i = 0; i < polygon_cp.vertex_num; i++){
        this->vertex[i].x = polygon_cp.vertex[i].x;
        this->vertex[i].y = polygon_cp.vertex[i].y;
    }
}

// コピーの代入演算子
Polygon& Polygon::operator=(const Polygon& polygon_cp){
    // 自身の代入チェック
    if(this != &polygon_cp){
        delete[] vertex;
        this->vertex_num = polygon_cp.vertex_num;
        this->vertex = new Point[polygon_cp.vertex_num];
        for(int i = 0; i < polygon_cp.vertex_num; i++){
            this->vertex[i].x = polygon_cp.vertex[i].x;
            this->vertex[i].y = polygon_cp.vertex[i].y;
        }
    }
    return *this;
}

string Polygon::get_name() const{
    return "Polygon";
}

float Polygon::compute_area() const{
    float result = 0, temp;
    for(int i = 0; i < this->vertex_num; i++){
        temp = (((this->vertex[i].x)*(this->vertex[(i+1) % vertex_num].y)) - ((vertex[i].y)*(vertex[(i+1) % vertex_num].x)));
        result += temp;
    }
    result /= 2;
    return result;
}

Polygon* Polygon::create() const{
    Polygon *Pol_new = new Polygon();
    return Pol_new;
}

Polygon* Polygon::clone() const{
    Polygon *Pol_clo = new Polygon(*this);
    return Pol_clo;
}

Polygon::~Polygon(){
    delete [] this;
}