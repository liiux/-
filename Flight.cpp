#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include"Others.h"
#include"Flight.h"
#include"index.h"
#include"Delete.h"
#include"Write.h"
#include"Search.h"
#include"Modify.h"
#include"Initialize.h"
#include<direct.h>
#include"background.h"
#include"Passenger.h"
using namespace std;
Flight::Flight() {}
Flight::Flight(int n) {
	if (n == -1) {
		char s[30] = "NAF";
		Copy_char(s, StartPlace);
	}
}
Flight::Flight(const char startplace[30], const char endplace[30], const char planenumber[30], Date departuredate, Time starttime, Time endtime, int firstprice, int secondprice, int thirdprice) {
	Copy_char(startplace, StartPlace);
	Copy_char(endplace, EndPlace);
	Copy_char(planenumber, PlaneNumber);
	DepartureDate = departuredate;
	StartTime = starttime;
	EndTime = endtime;
	FirstPrice = firstprice;
	SecondPrice = secondprice;
	ThirdPrice = thirdprice;
	FirstLength = 4;
	FirstWidth = 8;
	FirstRemain = FirstLength*FirstWidth;
	SecondLength = 8;
	SecondWidth = 8;
	SecondRemain = SecondLength*SecondWidth;
	ThirdLength = 12;
	ThirdWidth = 8;
	ThirdRemain = ThirdLength*ThirdWidth;
	Seat seat(0, -1);
	FirstSeat = SecondSeat = ThirdSeat = seat;
	for (int i = 0; i < FirstLength; i++) {
		for (int j = 0; j < FirstWidth; j++) {
			FirstClass[i][j][0] = '\0';
		}
	}//Seat中x对应排,y对应列，Length对应排数，Width对应列数
	for (int i = 0; i < SecondLength; i++) {
		for (int j = 0; j < SecondWidth; j++) {
			SecondClass[i][j][0] = '\0';
		}
	}
	for (int i = 0; i < ThirdLength; i++) {
		for (int j = 0; j < ThirdWidth; j++) {
			ThirdClass[i][j][0] = '\0';
		}
	}
	//Copy_char("", FlightNumber);
	FlightNumber[0] = '\0';
	strcat_s(FlightNumber, "Flight No._");
	int P1 = PlaceToNum(StartPlace);
	int P2 = PlaceToNum(EndPlace);
	if (P1 < 100) strcat_s(FlightNumber, "0");
	if (P1 < 10)strcat_s(FlightNumber, "0");
	char PP1[5];
	_itoa_s(P1, PP1, 10);
	strcat_s(FlightNumber, PP1);
	if (P2 < 100)strcat_s(FlightNumber, "0");
	if (P2 < 10)strcat_s(FlightNumber, "0");
	char PP2[5];
	_itoa_s(P2, PP2, 10);
	strcat_s(FlightNumber, PP2);
	//初始化的时候仅仅录入航班号的前缀，在录入文件时，再根据所处位置添加后缀
}
bool Flight::ifFirstFull() {
	if (FirstRemain == 0)return 1;
	else return 0;
}
bool Flight::ifSecondFull() {
	if (SecondRemain == 0)return 1;
	else return 0;
}
bool Flight::ifThirdFull() {
	if (ThirdRemain == 0)return 1;
	else return 0;
}
int Flight::getFirstRemain() {
	return FirstRemain;
}
int Flight::getSecondRemain() {
	return SecondRemain;
}
int Flight::getThirdRemain() {
	return ThirdRemain;
}
char* Flight::getStartPlace() {
	return StartPlace;
}
char* Flight::getEndPlace() {
	return EndPlace;
}
char* Flight::getFlightNumber() {
	return FlightNumber;
}
char* Flight::getPlaneNumber() {
	return PlaneNumber;
}
Date Flight::getDepartureDate() {
	return DepartureDate;
}
Time Flight::getStartTime() {
	return StartTime;
}
Time Flight::getEndTime() {
	return EndTime;
}
int Flight::getFirstPrice() {
	return FirstPrice;
}
int Flight::getSecondPrice() {
	return SecondPrice;
}
int Flight::getThirdPrice() {
	return ThirdPrice;
}
char* Flight::getFirstClass(int i, int j){
    return FirstClass[i][j];

}
char* Flight::getSecondClass(int i, int j){
    return SecondClass[i][j];
}
char* Flight::getThirdClass(int i, int j){
    return ThirdClass[i][j];
}
int Flight::getFirstLength(){
    return FirstLength;
}
int Flight::getFirstWidth(){
    return FirstWidth;
}
int Flight::getSecondLength(){
    return SecondLength;
}
int Flight::getSecondWidth(){
    return SecondWidth;
}
int Flight::getThirdLength(){
    return ThirdLength;
}
int Flight::getThirdWidth(){
    return ThirdWidth;
}
//调用该函数之前需要判断是否还有座位
Seat Flight::addFirstPassager(char passager[20]) {
    for (int i = 0; i < FirstLength; i++) {
            for (int j = 0; j < FirstWidth; j++) {
                if (strcmp(FirstClass[i][j], "\0") == 0) {
                    strcpy_s(FirstClass[i][j], passager);
                    Seat s(i, j);
                    FirstRemain--;
                    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
                    return s;
                }
            }
        }
}
bool Flight::CanPushFirst() {
	return !FirstQueue.isFull();
}
void Flight::pushFirstQueue(char passager[20]) {
	FirstQueue.push(passager);
}
int Flight::getFirstQueueNum() {
	return FirstQueue.getNum();
}
void Flight::CancelFirstTicket(int x,int y) {
	if (this->getFirstQueueNum() == 0) {
        strcpy_s(FirstClass[x][y],"\0");
        FirstRemain++;

	}//如果没有排队
	else {
        char passagerID[20];
        strcpy_s(passagerID,FirstQueue.pop());
        Passenger fortunateguy;
        while(1)
        {
            fortunateguy=FindPassenger(passagerID);
            fortunateguy.update_beforeFlight();
            if(fortunateguy.get_num_beforeFlight()<5)
                break;
            if(FirstQueue.isEmpty()==1){
                return;
            }
            strcpy_s(passagerID,FirstQueue.pop());
        }
        strcpy_s(FirstClass[x][y], passagerID);
        fortunateguy=FindPassenger(passagerID);
        fortunateguy.update_beforeFlight();
        fortunateguy.update_TicketsAssistantFlight();
        FlightID fid(getStartPlace(), getEndPlace(), getFlightNumber(), getPlaneNumber(), getDepartureDate(), getStartTime(), getEndTime(), 1, x+1, y+1, getFirstPrice());
        fortunateguy.success_TicketsAssistant(fid);
        fortunateguy.BookTicket(fid);
        AlterPassenger(fortunateguy);
	}//有人排队
    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}
Seat Flight::addSecondPassager(char passager[20]) {
    for (int i = 0; i < SecondLength; i++) {
            for (int j = 0; j < SecondWidth; j++) {
                if (strcmp(SecondClass[i][j], "\0") == 0) {
                    strcpy_s(SecondClass[i][j], passager);
                    Seat s(i, j);
                    SecondRemain--;
                    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
                    return s;
                }
            }
        }
}
bool Flight::CanPushSecond() {
	return !SecondQueue.isFull();
}
void Flight::pushSecondQueue(char passager[20]) {
	SecondQueue.push(passager);
}
int Flight::getSecondQueueNum() {
	return SecondQueue.getNum();
}
void Flight::CancelSecondTicket(int x,int y) {
	if (this->getSecondQueueNum() == 0) {
        strcpy_s(SecondClass[x][y], "\0");
		SecondRemain++;
        ModifyByFlightNumber(this->getDepartureDate(), this->getFlightNumber(), *this);

	}//如果没有排队
	else {
        char passagerID[20];
        strcpy_s(passagerID,SecondQueue.pop());
        Passenger fortunateguy;

        while(1)
        {
            fortunateguy=FindPassenger(passagerID);
            fortunateguy.update_beforeFlight();
            if(fortunateguy.get_num_beforeFlight()<5)
                break;
            if(SecondQueue.isEmpty()==1){
                return;
            }
            strcpy_s(passagerID,SecondQueue.pop());
        }

        strcpy_s(SecondClass[x][y], passagerID);
        fortunateguy=FindPassenger(passagerID);
        fortunateguy.update_TicketsAssistantFlight();
        FlightID fid(getStartPlace(), getEndPlace(), getFlightNumber(), getPlaneNumber(), getDepartureDate(), getStartTime(), getEndTime(), 2, x+1, y+1, getFirstPrice());
        fortunateguy.BookTicket(fid);
        AlterPassenger(fortunateguy);
	}//有人排队
    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}
Seat Flight::addThirdPassager(char passager[20]) {
    for (int i = 0; i < ThirdLength; i++) {
            for (int j = 0; j < ThirdWidth; j++) {
                if (strcmp(ThirdClass[i][j], "\0") == 0) {
                    strcpy_s(ThirdClass[i][j], passager);
                    Seat s(i, j);ThirdRemain--;
                    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
                    return s;
                }
            }
        }
}
bool Flight::CanPushThird() {
	return !ThirdQueue.isFull();
}
void Flight::pushThirdQueue(char passager[20]) {
	ThirdQueue.push(passager);
}
int Flight::getThirdQueueNum() {
	return ThirdQueue.getNum();
}
void Flight::CancelThirdTicket(int x,int y) {
	if (this->getThirdQueueNum() == 0) {
        strcpy_s(ThirdClass[x][y], "\0");
		ThirdRemain++;
	}//如果没有排队
	else {
        char passagerID[20];
        strcpy_s(passagerID,ThirdQueue.pop());
        Passenger fortunateguy;

        while(1)
        {
            fortunateguy=FindPassenger(passagerID);
            fortunateguy.update_beforeFlight();
            if(fortunateguy.get_num_beforeFlight()<5)
                break;
            if(ThirdQueue.isEmpty()==1){
                return;
            }
            strcpy_s(passagerID,ThirdQueue.pop());
        }

        strcpy_s(ThirdClass[x][y], passagerID);
        fortunateguy=FindPassenger(passagerID);
        fortunateguy.update_TicketsAssistantFlight();
        FlightID fid(getStartPlace(), getEndPlace(), getFlightNumber(), getPlaneNumber(), getDepartureDate(), getStartTime(), getEndTime(), 3, x+1, y+1, getFirstPrice());
        fortunateguy.BookTicket(fid);
        AlterPassenger(fortunateguy);

	}//有人排队
    ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}
void Flight::setFinalFlightNumber(int num) {
	char NN[5];
	_itoa_s(num, NN, 10);
	strcat_s(FlightNumber, NN);
}
bool Flight::ifBookAgain(char passager[20]){
    for (int i = 0; i < FirstLength; i++) {
            for (int j = 0; j < FirstWidth; j++) {
                if (strcmp(FirstClass[i][j], passager) == 0) {
                    return 1;
                }
            }
        }
    for (int i = 0; i < SecondLength; i++) {
            for (int j = 0; j < SecondWidth; j++) {
                if (strcmp(SecondClass[i][j], passager) == 0) {
                    return 1;
                }
            }
        }
    for (int i = 0; i < ThirdLength; i++) {
            for (int j = 0; j < ThirdWidth; j++) {
                if (strcmp(ThirdClass[i][j], passager) == 0) {
                    return 1;
                }
            }
        }
    return 0;
}

void Flight::DeleteFirstQueue(char passager[20]) {
	FirstQueue.Delete(passager);
	ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}
void Flight::DeleteSecondQueue(char passager[20]) {
	SecondQueue.Delete(passager);
	ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}
void Flight::DeleteThirdQueue(char passager[20]) {
	ThirdQueue.Delete(passager);
	ModifyByFlightNumber2(this->getDepartureDate(), this->getFlightNumber(), *this);
}


