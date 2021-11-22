#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int compute(int g, int a, int p){
    int r, y = 1;
    while (a > 0){
        r = a % 2;
        if (r == 1){
            y = (y * g) % p;
        }
        g = g * g % p;
        a = a / 2;
    }
    return y;
}

int main(){
    int a,A,b,B, kA, kB;
    int p = 23;
    int g = 5;
    srand ( time(NULL) );
    a = rand() % 50;
    b = rand() % 50;
    printf("%d %d \n", a, b);
    A = compute(g, a, p);
    B = compute(g, b, p);
    
    printf("%d %d \n", A, B);
    kA = compute(B,a,p);
    kB = compute(A,b,p);
    printf("%d %d \n", kA, kB);
    return 0;
}