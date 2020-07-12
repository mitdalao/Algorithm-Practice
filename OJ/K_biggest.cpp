#include<stdio.h>
int A[1000000];
int Partition(int L, int R){
    int pivot = L;
    int pivot_value = A[pivot];
    for(int i = L + 1; i <= R; i++){
        if(A[i] > pivot_value){
            pivot++;
            int temp = A[pivot];
            A[pivot] = A[i];
            A[i] = temp;
        }
    }
    int temp = A[L];
    A[L] = A[pivot];
    A[pivot] = temp;
    // for(int i = L; i <= R; i++){
    //     printf("%d ", A[i]);
    // }
    // printf("\n");
    return pivot;
}
int QuickSelection(int L, int R, int order){
    if(L < R){
        int p = Partition(L, R);
        int r = p - L + 1;
        if(r > order){
            return QuickSelection(L, p - 1, order);
        }
        else if(r < order){
            return QuickSelection(p + 1, R, order - r);
        }
        else{
            return A[p];
        }
    }
    else if(L == R){
        return A[L];
    }
}
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++)
        scanf("%d", &A[i]);
    printf("%d\n", QuickSelection(0, m - 1, n));
    return 0;
}