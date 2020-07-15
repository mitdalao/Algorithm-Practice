#include<stdio.h>
int gcd(int a, int b){
    while(b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        printf("%d\n", a * b / gcd(a, b));
    }
    return 0;
}