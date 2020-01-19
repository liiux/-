#pragma once
#include<iostream>
#include<string>
#include"background.h"
#include<stdlib.h>

using namespace std;
void Copy_char(const char a[], char b[]);
bool ifRight(char s[]);
class cycleQueue {
private:
	int m_size = 21;
	int m_front;
	int m_rear;
	int num;
	char tmp[20];
	char m_data[21][20];//够存20个数据
public:
	cycleQueue();
	bool isEmpty();
	bool isFull();
	void push(char ele[20]);
	int getNum();
	char* pop();
    void Delete(char ele[20]);
};

class Seat {
private:
	int x;
	int y;
	char SeatString[30];
public:
	Seat();
	Seat(int a, int b);
	char* showSeat();
	Seat & operator =(Seat p);
	int getX();
	int getY();
	void Xadd();
	void Yadd();
	void YTo0();
};
class Date {
private:
	int year; int month; int day;
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date & p);
	Date & operator =(Date p);
	int mycompare(Date d);//Date>d的时候返回1，Date<d的时候返回-1，Date=d的时候返回0
	void setDate(int y, int m, int d);
	int getYear();
	int getMonth();
    int getDay();
};
class Time {
private:
	int hour; int minute; int second;
public:
	Time();
	Time(int h, int m, int s);
	Time(const Time & p);
	Time & operator =(Time p);
	int mycompare(Time t);//Time>t的时候返回1，Time<t的时候返回-1，Time=t的时候返回0
	void setTime(int h, int m, int s);
	int getHour();
	int getMinute();
	int getSecond();

};
