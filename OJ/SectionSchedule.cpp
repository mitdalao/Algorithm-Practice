/*
题目描述:区间调度问题
有n项工作，每项工作分别在si开始，ti结束。对于每项工作，小李子可以选择参与与否，一旦他参与了某项工

作，他必须

一直工作直到工作时间结束。并且每项工作一旦开始就不能在中途参与（即使某次工作的结束瞬间与下次工作的

开始瞬间重合也不能参与）

小李子很缺钱，他想参与尽可能多的工作。请告诉他

他最多可以参与多少项工作，以便他做一个经济计划。

限制条件：
1<=N<=100000
0<=si<=ti<=10^9

输入
第一行输入n，表示有N项工作。
接下来一行输入每项工作的开始时间；
接下来一行输入每项工作的结束时间；

输出
最多参与的工作的数量
样例输入 Copy
5
1 2 4 6 8
3 5 7 9 10
样例输出 Copy
3
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Task{
    int b;
    int e;
}t[100000];
bool cmp(const Task& x, const Task& y){
    if(x.e == y.e)
        return x.b < y.b;
    return x.e < y.e;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &t[i].b);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &t[i].e);
        }
        sort(t, t + n, cmp);
        int res = 0;
        int end = -1;
        for(int i = 0; i < n; i++){
            if(t[i].b > end){
                res++;
                end = t[i].e;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}