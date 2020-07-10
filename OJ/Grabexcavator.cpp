/*
题目描述:(PAT B1032 挖掘机技术哪家强)
为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：
输入在第 1 行给出不超过 10
​5
​​  的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

*/

#include<stdio.h>
#include<memory.h>
int score[100010] = {0};
int main(){
    int N;
    int d, s;
    int o, m;
    while(scanf("%d", &N) != EOF){
        m = -1;
        o = -1;
        memset(score, 0, 100010 * 4);
        for(int i = 0; i < N; i++){
            scanf("%d%d", &d,&s);
            score[d] += s;
            if(score[d] > m){
                o = d;
                m = score[d];
            }
        }
        printf("%d %d\n", o, m);
    }
    return 0;
}