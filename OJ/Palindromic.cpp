/*
题目描述:codeup 问题 I: 【字符串】回文串
读入一串字符，判断是否是回文串。“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。

输入
一行字符串，长度不超过255。

输出
如果是回文串，输出“YES”，否则输出“NO”。

样例输入 Copy
12321
样例输出 Copy
YES
*/
#include<stdio.h>
#include<string.h>
char str[256];
int main(){
    while(scanf("%s", str) != EOF){
        int m = strlen(str);
        bool flag = false;
        for(int i = 0, j = m - 1; i <= j; i++, j--){
            if(str[i] != str[j]){
                flag = true;
                break;
            }
        }
        if(flag)
            printf("NO\n");
        else
        {
            printf("YES\n");
        }
        
    }
    return 0;
}