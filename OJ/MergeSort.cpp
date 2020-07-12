/*
题目描述:
归并排序是一个时间复杂度为O(nlogn)的算法，对于大量数据远远优于冒泡排序与插入排序。

这是一道排序练习题，数据量较大，请使用归并排序完成。


输入
第一行一个数字n，代表输入的组数

其后每组第一行输入一个数字m，代表待排序数字的个数

其后m行每行一个数据，大小在1～100000之间，互不相等，最多有10万个数据。

输出
升序输出排好序的数据，每行一个数字
样例输入 Copy
1
10
10
9
8
7
6
5
4
3
2
1
样例输出 Copy
1
2
3
4
5
6
7
8
9
10*/
#include<stdio.h>
int A[100010];
int temp[100010];
void Merge(int LL, int LR, int RL, int RR){
    int idx = LL;
    int i = LL, j = RL;
    while(i <= LR && j <= RR){
        if(A[i] <= A[j])
            temp[idx++] = A[i++];
        else
            temp[idx++] = A[j++];
    }
    while(i <= LR){
        temp[idx++] = A[i++];
    }
    while(j <= RR){
        temp[idx++] = A[j++];
    }
    for(int k = LL; k <= RR; k++)
        A[k] = temp[k];

}
void MergeSort(int L, int R){
    if(L < R){
        int mid = (L + R) / 2;
        MergeSort(L, mid);
        MergeSort(mid + 1, R);
        Merge(L, mid, mid + 1, R);
    }
}
int main(){
    int m, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
            scanf("%d", &A[j]);
        MergeSort(0, m - 1);
        for(int j = 0; j < m; j++)
            printf("%d\n", A[j]);
    }
    return 0;
}