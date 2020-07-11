/*
题目描述:全排列
有1～n这n（n<=9）个数，现将这n个数组成一个n位的数，对于这n个数，每个数只取一次，例如n=2，则12，21等都是符合条件的数。问，输入n后，将符合条件的所有的n位数输出，且按照从小到大顺序输出。
输入
输入1行：一个正整数数n。
输出
输出2行： 
由小于n的数组成的多个n位数。 
总方案数
样例输入 Copy
2
样例输出 Copy
12
21
2
*/
#include<stdio.h>
int res[9];
bool number[10];
int count = 0;
void allPermutation(int layer, int n){
    if(layer == n){
        count++;
        for(int i = 0; i < n; i++)
            printf("%d", res[i]);
        printf("\n");
    }
    else{
        for(int i = 1; i <= n; i++){
            if(number[i] == false){
                number[i] = true;
                res[layer] = i;
                allPermutation(layer+1, n);
                number[i] = false;
            }
        }
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        count = 0;
        for(int i = 1; i <= 10; i++)
            number[i] = false;
        allPermutation(0, n);
        printf("%d\n",count);
    }
    return 0;
}