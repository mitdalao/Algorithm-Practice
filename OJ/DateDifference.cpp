/*
题目描述:codeup日期差值
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值
*/
#include<stdio.h>
int date[10000][13][32] = {0};
int day_of_month[][2] = {
     0,  0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30, 
    31, 31,
    30, 30,
    31, 31
};
bool isLeapYear(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
    {
        return false;
    }
    
}
struct Date{
    int year;
    int month;
    int day;
    Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    void Next(){
        day++;
        if(day > day_of_month[month][isLeapYear(year)]){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
};
int main(){
    Date d(0, 1, 1);
    int day = 1;
    while(d.year < 10000){
        date[d.year][d.month][d.day] = day;
        d.Next();
        day++;
    }
    int year1, month1, day1;
    int year2, month2, day2;
    while(scanf("%4d%2d%2d", &year1, &month1, &day1) != EOF && scanf("%4d%2d%2d", &year2, &month2, &day2) != EOF){
        int diff = date[year1][month1][day1] - date[year2][month2][day2];
        if (diff < 0)
            diff = -diff + 1;
        else
        {
            diff = diff + 1;
        }
        
        printf("%d\n", diff);
    }
    return 0;
}