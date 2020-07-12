#include<stdio.h>
//A[]为严格递增序列，left为二分下界，right为二分上界，x为欲查询的数
//二分区间为左闭右闭的[left, right]，传入的初值为[0, n-1]
int BinarySearch(int A[], int left, int right, int x){
    while(left <= right){
        int mid = (left + right) / 2;
        if(A[mid] < x){
            left = mid + 1;
        }
        else if(A[mid] > x){
            right = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

//A[]为递增序列(可重复)，x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分区间为左闭右闭的[left, right]，传入的初值为[0, n]
//注：循环终止条件left == right，初值右端点是n，if的条件不能改成A[mid] <= x
int lower_bound(int A[], int left, int right, int x){
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] >= x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

//A[]为递增序列(可重复)，x为欲查询的数，函数返回第一个大于x的元素的位置
//二分区间为左闭右闭的[left, right]，传入的初值为[0, n]
int upper_bound(int A[], int left, int right, int x){
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] > x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}


//二分法求实数近似解
//重点是递增关系，f是关于x的递增函数
const double eps = 1e-5;
double f(double x){
    return ;
}
double solve(double L, double R){
    double left = L, right = R;
    double mid;
    while(right - left > eps){
        mid = (left + right) / 2;
        if(f(mid) > 0){
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return mid;
}
