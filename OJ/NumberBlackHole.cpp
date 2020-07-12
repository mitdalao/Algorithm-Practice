#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool bigger(char a, char b){
    return a > b;
}
int charArrayToint(char *str, int length){
    int res = 0;
    for(int i = 0; i < length; i++){
        res = res * 10 + str[i] - '0';
    }
    return res;
}
void intToCharArray(char *str, int x, int length){
    str[length] = '\0';
    int idx = length - 1;
    while(x > 0){
        str[idx--] = (x % 10) + '0';
        x = x / 10;
    }
    while(idx >= 0){
        str[idx--] = '0';
    }
}
int main(){
    int x;
    char str[5];
    char rev[5];
    char diff[5];
    scanf("%d", &x);
    intToCharArray(str, x, 4);
    sort(str, str + 4, bigger);
    for(int i = 0; i < 4; i++){
        rev[i] = str[3 - i];
    }
    rev[4] = '\0';
    int a = charArrayToint(str, 4);
    int b = charArrayToint(rev, 4); 
    while(a - b != 6174 && a - b != 0){
        intToCharArray(diff, a - b, 4);
        printf("%s - %s = %s\n", str, rev, diff);
        intToCharArray(str, a - b, 4);
        strcpy(rev, str);
        sort(str, str + 4, bigger);
        for(int i = 0; i < 4; i++){
            rev[i] = str[3 - i];
        }
        a = charArrayToint(str, 4);
        b = charArrayToint(rev, 4); 
    }
    intToCharArray(diff, a - b, 4);
    printf("%s - %s = %s\n", str, rev, diff);
    return 0;
}