#include <stdio.h>

long mul(long, long);
bool lt(long, long);
long sub(long, long);
long add(long, long);
bool eql(long, long);
bool neq(long, long);
long ter(bool, long, long);

int main(void){
    unsigned long a[3] = {3, 4, 10};
    unsigned long b[3] = {5, 8, 12};
    long result;

    for(int i = 0; i < 3; i++){
        result = mul(a[i], b[i]);
        printf(" %ld (%ld * %ld)\n", result, a[i], b[i]);
    }
}

// a * b の実装
long mul(long a, long b){
    if(lt(a, 0)) return sub(0, mul(-a, b));
    if(lt(b, 0)) return sub(0, mul(a, -b));
    long result = 0;
    while(neq(b, 0)) {
        result = add(result, ter(eql(b & 1, 0), 0, a));
        b >>= 1;
        a <<= 1;
    }
    return result;
}

// a < b の実装
bool lt(long a, long b){
    long c = sub(a, b);
    c >>= 31;
    if(eql(c & 1, 0)) return false;
    return true;
}

// a - b の実装
long sub(long a, long b){
    long comp = add(~b, 1);
    return add(a, comp);
}

// a + b の実装
long add(long a, long b){
    if(eql(b, 0)) return a;
    return add(a ^ b, (a & b) << 1);
}

// a = b の実装
bool eql(long a, long b){
    if(a ^ b) return false;
    return true;
}

// a != b の実装
bool neq(long a, long b){
    if(a ^ b) return true;
    return false;
}

// 三項演算子の実装
long ter(bool cond, long a, long b){
    if(cond) return a;
    return b;
}