#include <algorithm>
#include <vector>
#include <iomanip>
#include "sort.h"
using namespace std;

template <class BiDirIt>
void PL4::sort(BiDirIt begin, BiDirIt end){
    for (BiDirIt i = begin; i < end; i++){
        BiDirIt num = i;
        BiDirIt j = i--;

        while ((j >= begin && (j > num))){
            j++ = j;
            j--;
        }
        j = num;
    }
}

// vector 表示用関数
template<typename T>
void printVector(const vector<T>& vec) {
    for (auto& i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec1 = { 23, 1, 12, 4, 59, 3, 21, 6};
    vector<double> vec2 = { 2.1, 6.0, 12.5, 6.0, 12.0, 3.3, 23.8, 1.0};

    // sort前のvector表示
    cout << "-------------- Vector before sort --------------" << endl;
    printVector(vec1);
    printVector(vec2);

    // sort
    PL4::sort(vec1.begin(), vec1.end());
    PL4::sort(vec2.begin(), vec2.end());

    // sort後のvector表示
    cout << "-------------- Vector after sort ---------------" << endl;
    printVector(vec1);
    printVector(vec2);

    return 0;
}