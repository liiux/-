#include "Delete.h"
void DeleteByFlightNumber(Date date, char FlightNumber[30]) {
	int year = date.getYear();
	int month = date.getMonth();
	int day = date.getDay();
	char Y[10];
	char M[5];
	char D[5];
	_itoa_s(year, Y, 10);
	_itoa_s(month, M, 10);
	_itoa_s(day, D, 10);
    char address[100] = "../航班信息/";
    //char address[100] = "C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\";
	strcat_s(address, Y);
	strcat_s(address, "-");
	if (month < 10)strcat_s(address, "0");
	strcat_s(address, M);
	strcat_s(address, "-");
	if (day < 10)strcat_s(address, "0");
	strcat_s(address, D);
	strcat_s(address, ".dat");

	char PP1[5];
	PP1[0] = FlightNumber[11];
	PP1[1] = FlightNumber[12];
	PP1[2] = FlightNumber[13];
	PP1[3] = '\0';
	char PP2[5];
	PP2[0] = FlightNumber[14];
	PP2[1] = FlightNumber[15];
	PP2[2] = FlightNumber[16];
	PP2[3] = '\0';
	char PP[5];
	PP[0] = FlightNumber[17];
	PP[1] = '\0';
	int P1 = atoi(PP1);
	int P2 = atoi(PP2);
	int P = atoi(PP);
	fstream f(address, ios::binary | ios::out | ios::in);
	IndexPoint ip;
	int p = calculatePages(AirPorts[P1], AirPorts[P2]);
	f.seekg(p * sizeof(IndexPoint), ios::beg);
	f.read((char *)&ip, sizeof(IndexPoint));
	ip.position[P] = -1;
	ip.number--;
	if (P == ip.Max) { ip.Max--; }
	f.seekp(p * sizeof(IndexPoint), ios::beg);
	f.write((char *)&ip, sizeof(IndexPoint));
}
