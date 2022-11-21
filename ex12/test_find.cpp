#include <iostream>
#include <vector>
#include "find.h"
using namespace std;

int main(){
    // 座標の設定
    vector<Point> points;
    points.push_back(Point(2.0,2.0,2.0));
    points.push_back(Point(3.0,3.0,3.0));
    points.push_back(Point(4.0,4.0,4.0));
    points.push_back(Point(5.0,5.0,5.0));
    points.push_back(Point(6.0,6.0,6.0));
    points.push_back(Point(7.0,7.0,7.0));

    // 関数
    vector<Point> closest = find_k_closest(points, 4);

    for (size_t i = 0; i < 4; i++) {
        cout << "x = " << closest[i].x << ", y = " << closest[i].y << ", z = " << closest[i].z << endl;
    }

    return 0;
}