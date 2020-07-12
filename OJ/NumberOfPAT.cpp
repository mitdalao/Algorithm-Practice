/*
题目描述: PAT(1040 有几个PAT)
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10
​5
​​ ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string str;
    cin >> str;
    vector<int> leftp;
    leftp.push_back(0);
    long long res = 0; 
    for(int i = 1; i < str.length(); i++){
        if(str[i - 1] == 'P')
            leftp.push_back(leftp[leftp.size() - 1] + 1);
        else
            leftp.push_back(leftp[leftp.size() - 1]);
    }
    int rightt = 0;
    for(int i = str.length() - 1; i > 0; i--){
        if(str[i] == 'T')
            rightt++;
        if(str[i] == 'A'){
            res = res + leftp[i] * rightt;
        }
    }
    printf("%lld\n", res % 1000000007);
    return 0;
}


/*
结果部分正确
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    vector<int> P;
    vector<int> A;
    vector<int> T;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'P')
            P.push_back(i);
        if(str[i] == 'A')
            A.push_back(i);
        if(str[i] == 'T')
            T.push_back(i);
    }
    int i = 0, j = 0, k = 0;
    long long res = 0;
    while(i < P.size()){
        while(j < A.size() && A[j] < P[i])
            j++;
        if(j == A.size())
            break;
        while(k < T.size() && T[k] < A[j])
            k++;
        if(k == T.size())
            break;
        res = res + (A.size() - j) * (T.size() - k);
        res = res % 1000000007;
        i++;
    }
    printf("%lld\n", res);
    return 0;
}
*/