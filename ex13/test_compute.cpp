#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// Q1
void compute_median(vector<float>& array){
    // begin, endの取得
    auto ar_begin = begin(array);
    auto ar_end = end(array);

    // 配列サイズの取得
    auto ar_size = distance(ar_begin, ar_end);
    // サイズが偶数か奇数で処理
    if (ar_size % 2 == 0){
        nth_element(ar_begin, ar_begin + (ar_size/2 - 1), ar_end);
        nth_element(ar_begin, ar_begin + (ar_size/2), ar_end);
    }
    else{
        nth_element(ar_begin, ar_begin + (ar_size/2), ar_end);
    }

    // ソート後の配列を表示
    cout << "After array: ";
    for (auto value : array) {
        cout << value << ", ";
    }
    cout << endl;

    // 結果の表示
    double median;
    if (ar_size % 2 == 0) {
        auto l_middle = ar_begin + (ar_size/2 - 1);
        auto r_middle = ar_begin + (ar_size/2);
        median = ((*l_middle) + (*r_middle)) / 2;
    }
    else{
        median = *(ar_begin + (ar_size/2));
    }

    cout << "Median: " << median << endl;
}

// Q2
vector<float> compute_k_closest(vector<float>& array, int k){
    // begin, endの取得
    auto ar_begin = begin(array);
    auto ar_end = end(array);

    // k回分のソートを行う
    for(int i = 0; i < k; i++){
        // maxのイテレータを取得
        vector<float>::iterator max_ite = max_element(ar_begin, ar_end);
        // 最大値を基準としてソート
        nth_element(ar_begin, max_ite, ar_end);
        // ソート範囲の変更
        ar_end--;
    }
    // 結果を返すvector
    vector<float> result(array.end()-k, array.end());

    return result;
}

int main(void) {
    vector<float> vec1 = {55.3, 28.2, -2, 18, 36.2, 4.2, 3.2, -42, -1.3};
    vector<float> vec2 = {3, 5.2, 6.9, 10, -1, 4.2, 8, 100};

    cout << "------------------ Q1 ------------------" << endl;
    // test for array1
    cout << "Before array1: ";
    for (auto value : vec1) {
        cout << value << ", ";
    }
    cout << endl;

    compute_median(vec1);

    // test for array2
    cout << "Before array2: ";
    for (auto value : vec2) {
        cout << value << ", ";
    }
    cout << endl;

    compute_median(vec2);


    cout << "------------------ Q2 ------------------" << endl;
    vector<float> result;

    // test for array1
    cout << "array1: ";
    result = compute_k_closest(vec1, 3);
    for (auto value : result) {
        cout << value << ", ";
    }
    cout << endl;

    // test for array2
    cout << "array2: ";
    result = compute_k_closest(vec2, 3);
    for (auto value : result) {
        cout << value << ", ";
    }
    cout << endl;

    return 0;
}