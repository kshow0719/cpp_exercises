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

    // 関数
    vector<Point> closest = find_k_closest(points, 3);

    for (size_t i = 0; i < 3; i++) {
        cout << "x = " << closest[i].x << ", y = " << closest[i].y << ", z = " << closest[i].z << endl;
    }

    return 0;
}