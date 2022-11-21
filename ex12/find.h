#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#ifndef FIND_H
#define FIND_H

// Point構造体
struct Point {
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

// Compare関数オブジェクト
class Compare{
private:
    /* data */
public:
    bool operator ()(const Point& first, const Point& second);
};

/// 関数 find_k_closest()
vector <Point> find_k_closest(vector <Point> P, int k){
    priority_queue<double, vector<Point>, decltype(Compare())> queue{Compare()};

    for (int i = P.size()-1; i >= 0; i--){
        queue.push(P[i]);
    }

    vector<Point> result;
    for (int i = 0; i < k; i++) {
        result.push_back(queue.top());
        queue.pop();
    }

    return result;
}

#endif // FIND_H