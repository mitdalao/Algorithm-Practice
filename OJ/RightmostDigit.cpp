#include<stdio.h>
int Binary(long long x, int index, int m){
    if(index == 0){
        return 1;
    }
    else{
        if(index % 2 == 1){
            return x * Binary(x, index - 1, m) % m;
        }
        else{
            int mul = Binary(x, index / 2, m);
            return mul * mul % m;
        }
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        long long x;
        for(int i = 0; i < n; i++){
            scanf("%lld", &x);
            printf("%d\n", Binary(x, x, 10));
        }
    }
    return 0;
}