#include<stdio.h>
bool notPrime[500001] = {false};
int primeNumber[10001];
int primeNo = 1;
int main(){
    for(int i = 2; i <= 500000; i++){
        if(notPrime[i] == false){
            primeNumber[primeNo++] = i;
            if(primeNo > 10000)
                break;
            for(int j = 2 * i; j <= 500000; j += i){
                notPrime[j] = true;
            }
        }
    }
    int M, N;
    while(scanf("%d%d", &M, &N) != EOF){
        int n = N <= primeNo ? N : primeNo;
        for(int i = M; i <= n; i++)
        {
            if((i - M + 1) % 10 == 0 || i == n)
                printf("%d\n", primeNumber[i]);
            else
                printf("%d ", primeNumber[i]);
        }
    }
    return 0;
}