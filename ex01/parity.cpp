#include <stdio.h>

int parity(long);

int main(void){
    unsigned long x[4] = {3, 10, 28, 106};
    int result;

    for(int i = 0; i < 4; i++){
        result = parity(x[i]);
        printf("%d (x = %ld)\n", result, x[i]);
    }
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

    if(sum % 2 == 1){
        return 0;
    }
    else{
        return 1;
    }
}