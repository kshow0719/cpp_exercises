#include <iostream>
#include <vector>
#include "find.h"
using namespace std;

int main(){
    // 座標の設定
    vector<Point> points;
    points.push_back(Point(1.0, 1.0, 1.0));
    points.push_back(Point(3.0, 2.0, 5.3));
    points.push_back(Point(4.0, 4.0, 2.0));
    points.push_back(Point(6.6, 5.0, 7.6));
    points.push_back(Point(1.3, 4.5, 8.0));
    points.push_back(Point(7.0, 9.0, 7.0));

    cout << "-------------- Q1 --------------" << endl;
    // find_k_closest関数
    vector<Point> closest = find_k_closest(points, 3);

    for (size_t i = 0; i < 3; i++) {
        cout << "x = " << closest[i].x << ", y = " << closest[i].y << ", z = " << closest[i].z << endl;
    }

    cout << "-------------- Q2 --------------" << endl;
    // find_k_closest_lambda関数
    vector<Point> lambda = find_k_closest_lambda(points, 3);

    for (size_t i = 0; i < 3; i++) {
        cout << "x = " << lambda[i].x << ", y = " << lambda[i].y << ", z = " << lambda[i].z << endl;
    }

    return 0;
}