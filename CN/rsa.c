#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int a, int b){
    if (b == 0){return a;}
    return gcd(b, a %b);
}

int main(){
    double p = 3, q = 7;
    double E = 2, D, N = p * q, Z = (p-1) * (q-1), k = 2, msg, c , m;
    while(E < Z){
        if (gcd(E,Z) == 1){break;}
        else{
            E ++;
        }
    }
    D = (1 + (k * Z)) / E ;
    msg = 12;
    c = pow(msg,E);
    c = fmod(c,N);
    m = pow(c,D);
    m = fmod(m,N);
    printf("Message : %f \n", msg);
    printf("p : %f \n", p);
    printf("q : %f \n", q);
    printf("N : %f \n", N);
    printf("E : %f \n", E);
    printf("D : %f \n", D);
    printf("Encrypted : %f \n", c);
    printf("Original : %f \n", m);
}