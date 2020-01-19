#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"background.h"
/*
class IndexPoint {
public:
int FlightCode;
int Pages;
IndexPoint(int a, int b) {
FlightCode = a;
Pages = b;
}
};
int BinarySearch(int FlightCode) {
int Left = 0;
int Right = 41005;
int size = sizeof(IndexPoint);
fstream f;
f.open("D:\\数据结构大作业\\航班订票管理系统\\FlightIndex.dat", ios::out | ios::in | ios::binary);
while (left <= right) {
int middle = (Left + Right) / 2;
f.seekg(middle*size, ios::beg);
IndexPoint ip(0,0);
f.read((char*)&ip, size);
if (FlightCode == ip.FlightCode) {
return ip.Pages;
}
if (FlightCode > ip.FlightCode) {
Left = middle + 1;
}
else {
Right = middle - 1;
}
}

}
int LookForFlightPages(int P1, int P2) {
//int P1 = PlaceToNum(Place1);
//int P2 = PlaceToNum(Place2);
if (P1 == 0 || P2 == 0) {
//此处跳转界面，无搜索航班
}
int P = P1 * 1000 + P2;
return BinarySearch(P);

}*/
class IndexPoint {
public:
	int ifWrite;
	int position[10];//最多容纳十个
	int number;
	int Max;
	int startNum;
	int endNum;
};
int calculatePages(const char Place1[30], const char Place2[30]);
void WriteIndex(char address[100]);
/*
void WriteIndex() {
fstream f;
f.open("D:\\数据结构大作业\\航班订票管理系统\\FlightIndex.dat", ios::out | ios::in | ios::binary);
int i, j;
int airportNum = 203;
int pages = 0;
for (i = 1; i <= airportNum; i++) {
for (j = 1; j <= airportNum; j++) {
if (j == i) continue;
int P = i * 1000 + j;
IndexPoint ip(P, pages);
pages++;
f.write((char*)&ip, sizeof(IndexPoint));
}
}
f.close();
}*/

