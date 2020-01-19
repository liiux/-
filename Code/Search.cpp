#include"Search.h"
#include<vector>
#include<io.h>
vector<Flight> Search(Date date, char Place1[30], char Place2[30]) {
	int year = date.getYear();
	int month = date.getMonth();
	int day = date.getDay();
	char Y[10];
	char M[5];
	char D[5];
	_itoa_s(year, Y, 10);
	_itoa_s(month, M, 10);
	_itoa_s(day, D, 10);
    char address[100] = "..\\航班信息\\";
    //char address[100] = "C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\";
	strcat_s(address, Y);
	strcat_s(address, "-");
	if (month < 10)strcat_s(address, "0");
	strcat_s(address, M);
	strcat_s(address, "-");
	if (day < 10)strcat_s(address, "0");
	strcat_s(address, D);
	strcat_s(address, ".dat");

	int p = calculatePages(Place1, Place2);
    if(p==-1){
        vector<Flight>result;
        return result;
    }
    intptr_t Handle;
    struct _finddata_t FileInfo;
    if ((Handle = _findfirst(address, &FileInfo)) == -1L){
        vector<Flight>result;
        return result;
    }
	fstream f;
	f.open(address, ios::out | ios::in | ios::binary);
	f.seekg(p * sizeof(IndexPoint), ios::beg);
	IndexPoint ip;
	f.read((char *)&ip, sizeof(IndexPoint));
    vector<Flight>result;
	for (int i = 0; i <= ip.Max; i++) {
		if (ip.position[i] == -1)continue;
		Flight F(-1);
		f.seekg(ip.position[i], ios::beg);
		f.read((char*)&F, sizeof(Flight));
        result.push_back(F);
	}
	f.close();
	return result;
}
Flight SearchByFlightNumber(Date date, char FlightNumber[30]) {
	int year = date.getYear();
	int month = date.getMonth();
	int day = date.getDay();
	char Y[10];
	char M[5];
	char D[5];
	_itoa_s(year, Y, 10);
	_itoa_s(month, M, 10);
	_itoa_s(day, D, 10);
    char address[50] = "..\\航班信息\\";
    //char address[100] = "C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\";
	strcat_s(address, Y);
	strcat_s(address, "-");
	if (month < 10)strcat_s(address, "0");
	strcat_s(address, M);
	strcat_s(address, "-");
	if (day < 10)strcat_s(address, "0");
	strcat_s(address, D);
	strcat_s(address, ".dat");

    intptr_t Handle;
    struct _finddata_t FileInfo;
    if ((Handle = _findfirst(address, &FileInfo)) == -1L){
        Flight f(-1);
        return f;
    }

    char Leter[20];
    for(int i=0;i<11;i++){
        Leter[i]=FlightNumber[i];
    }
    Leter[11]='\0';
    if(strcmp(Leter,"Flight No._")!=0){
        Flight f(-1);
        return f;
    }
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
    if(FlightNumber[18]!='\0'){
        Flight f(-1);
        return f;
    }
	int P1 = atoi(PP1);
	int P2 = atoi(PP2);
	int P = atoi(PP);
	fstream f(address, ios::binary | ios::out | ios::in);
	IndexPoint ip;
	int p = calculatePages(AirPorts[P1], AirPorts[P2]);
    if(p==-1){
        Flight f(-1);
        return f;

    }
	f.seekg(p * sizeof(IndexPoint), ios::beg);
	f.read((char *)&ip, sizeof(IndexPoint));
    if(P<0||P>ip.Max){
        Flight f(-1);
        return f;
    }
	int WWW = ip.position[P];
    if(WWW==-1){
        Flight f(-1);
        return f;
    }
	f.seekg(WWW, ios::beg);
	Flight flight;
	f.read((char*)&flight, sizeof(Flight));
	return flight;
}
