#include <algorithm>
#include <list>
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

// List 表示用関数
template<typename T>
void printList(const list<T>& list) {
    for (auto& i : list) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    list<int> list1 = { 23, 1, 12, 4, 59, 3, 21, 6};
    list<double> list2 = { 2.1, 6.0, 12.5, 6.0, 12.0, 3.3, 23.8, 1.0};

    // sort前のlist表示
    cout << "-------------- List before sort --------------" << endl;
    printList(list1);
    printList(list2);

    // sort
    // PL4::sort(list1.begin(), list1.end());
    // PL4::sort(list2.begin(), list2.end());

    // sort後のlist表示
    cout << "-------------- List after sort ---------------" << endl;
    printList(list1);
    printList(list2);

    return 0;
}