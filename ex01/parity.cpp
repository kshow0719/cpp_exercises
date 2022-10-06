#include <stdio.h>
#include <bitset>

int main(void){
    unsigned long x;

    std::cout << parity(2) << std::endl;
}

int parity(long x){
    int sum = 0;
    int r;

    while (x > 1)
    {
        r = x % 2;
        if(r == 1){
            sum++;
        }
        x = x / 2;
    }
    sum++;

    return sum;
}