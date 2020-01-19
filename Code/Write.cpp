#include"Write.h"
#include <QProgressBar>
#include <QApplication>
void WriteOne(char address[100], Flight flight) {
	char Place1[30];
	char Place2[30];
	strcpy_s(Place1, flight.getStartPlace());
	strcpy_s(Place2, flight.getEndPlace());
	int p = calculatePages(Place1, Place2);
	fstream f;
	f.open(address, ios::out | ios::in | ios::binary);
	f.seekg(p * sizeof(IndexPoint), ios::beg);
	IndexPoint ip;
	f.read((char *)&ip, sizeof(IndexPoint));
	if (ip.number >= 10) {
		//已满不能再添加了
	}
	else {
		f.seekp(0, ios::end);
		int FlightPosition = f.tellp();
		if (ip.number == ip.Max + 1) {
			flight.setFinalFlightNumber(ip.number);
			f.write((char*)&flight, sizeof(Flight));
			ip.position[ip.number] = FlightPosition;
			ip.Max++;
			ip.number++;
			f.seekp(p * sizeof(IndexPoint), ios::beg);
			f.write((char*)&ip, sizeof(IndexPoint));
		}
		else {
			int theD;
			for (theD = 0; theD < ip.Max; theD++) {
				if (ip.position[theD] == -1) { break; }
			}
			flight.setFinalFlightNumber(theD);
			f.write((char*)&flight, sizeof(Flight));
			ip.position[theD] = FlightPosition;
			ip.number++;
			f.seekp(p * sizeof(IndexPoint), ios::beg);
			f.write((char*)&ip, sizeof(IndexPoint));
		}
	}
	f.close();
	//Flie.open()
}
void Write(Date date, Flight flight) {
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
	fstream in;
	ofstream out;
	in.open(address);
	if (in.fail()) {
		out.open(address);
		WriteIndex(address);
	}
	WriteOne(address, flight);
}


void WriteTT(Date date, QProgressBar* qp) {
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
    ofstream out;
    out.open(address);
    WriteIndex(address);
    fstream f;
    f.open(address, ios::out | ios::in | ios::binary);
    int pp = 0;
    const int sum = 196020;
    char planes[5][20] = { "plane-1","plane-2","plane-3","plane-4","plane-5" };
    for (int i = 1; i <= 198; i++) {
        for (int j = 1; j <= 198; j++) {
            if (i == j)continue;
            int p = calculatePages(AirPorts[i], AirPorts[j]);
            IndexPoint ip;
            ip.ifWrite = 0;
            ip.number = 0;
            for (int i = 0; i < 10; i++) {
                ip.position[i] = 0;
            }
            ip.Max = -1;
            ip.startNum = i;
            ip.endNum = j;
            for (int T = 0; T < 5; T++) {
                Time start(6 + T * 3, 0, 0);
                Time end(10 + T * 3, 0, 0);
                Flight flight(AirPorts[i], AirPorts[j], planes[T], date, start, end, 1000, 500, 200);
                f.seekp(0, ios::end);
                int FlightPosition = f.tellp();
                ip.position[T] = FlightPosition;
                flight.setFinalFlightNumber(T);
                f.write((char*)&flight, sizeof(Flight));
                ip.Max++;
                ip.number++;
            }
            f.seekp(p * sizeof(IndexPoint), ios::beg);
            f.write((char*)&ip, sizeof(IndexPoint));
            pp = pp + 5;
            int num = (pp * 100) / sum;
            QApplication::processEvents();
            qp->setValue(num);
        }
    }
    qp->setValue(100);
    f.close();
}

