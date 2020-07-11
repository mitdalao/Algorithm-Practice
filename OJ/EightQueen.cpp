/*
题目描述:(八皇后)

会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。


输入

第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)


输出

输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。


样例输入 Copy
3
6
4
25
样例输出 Copy
25713864
17582463
36824175
*/
#include<stdio.h>
int pos[9];
int res[93][9];
int count = 0;
bool isOk(int r, int c){
    //up
    for(int i = 1; i < r; i++)
        if(pos[i] == c)
            return false;
    //upleft
    for(int i = 1; i < r; i++)
        if(pos[r - i] == c - i)
            return false;
    //upright
    for(int i = 1; i < r; i++)
        if(pos[r - i] == c + i)
            return false;
    return true;
}
void EightQueen(int layer){
    if(layer == 9){
        count++;
        for(int i = 1; i <= 8; i++){
            res[count][i] = pos[i];
        }
    }
    else{
        for(int i = 1; i <= 8; i++){
            if(isOk(layer, i)){
                pos[layer] = i;
                EightQueen(layer+1);
                pos[layer] = -1;
            }
        }
    }
}
int main(){
    EightQueen(1);
    int n;
    scanf("%d", &n);
    int order;
    for(int i = 0; i < n; i++){
        scanf("%d", &order);
        for(int i = 1; i <= 8; i++)
            printf("%d", res[order][i]);
        printf("\n");
    }
    return 0;
}