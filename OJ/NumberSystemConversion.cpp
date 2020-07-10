/*
题目描述: PAT(1022 D进制的A+B)
输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include<stdio.h>
int res[32];
int main(){
    int a, b;
    int sum;
    int d;
    while(scanf("%d%d", &a, &b) != EOF){
        scanf("%d", &d);
        sum = a + b;
        if(sum == 0){
            printf("0\n");
            continue;
        }
        int idx = 0;
        while(sum > 0){
            res[idx] = sum % d;
            sum = sum / d;
            idx++;
        }
        for(int i = idx - 1; i >= 0; i--){
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}