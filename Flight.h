#pragma once
#include<string>
#include"Others.h"
using namespace std;
class Flight {
private:
	char StartPlace[30];
	char EndPlace[30];
	char FlightNumber[30];
	char PlaneNumber[30];
	Date DepartureDate;
	Time StartTime;
	Time EndTime;
	int FirstLength;
	int FirstWidth;
	int FirstRemain;
    char FirstClass[4][8][20];
	Seat FirstSeat;
	int SecondLength;
	int SecondWidth;
	int SecondRemain;
	char SecondClass[8][8][20];
	Seat SecondSeat;
	int ThirdLength;
	int ThirdWidth;
	int ThirdRemain;
	char ThirdClass[12][8][20];
	Seat ThirdSeat;
	int FirstPrice;
	int SecondPrice;
	int ThirdPrice;
	cycleQueue FirstQueue;
	cycleQueue SecondQueue;
	cycleQueue ThirdQueue;

public:
	Flight();
	Flight(int n);
	Flight(const char startplace[30], const char endplace[30], const char planenumber[30], Date departuredate, Time starttime, Time endtime, int firstprice, int secondprice, int thirdprice);
	bool ifFirstFull();
	bool ifSecondFull();
	bool ifThirdFull();
	int getFirstRemain();
	int getSecondRemain();
	int getThirdRemain();
	int getFirstPrice();
	int getSecondPrice();
	int getThirdPrice();
	char * getStartPlace();
	char * getEndPlace();
	char * getFlightNumber();
    char * getPlaneNumber();
    char* getFirstClass(int, int);
    char* getSecondClass(int, int);
    char* getThirdClass(int, int);
    int getFirstLength();
    int getFirstWidth();
    int getSecondLength();
    int getSecondWidth();
    int getThirdLength();
    int getThirdWidth();
	Date getDepartureDate();
	Time getStartTime();
	Time getEndTime();

	Seat addFirstPassager(char passager[20]);
	void pushFirstQueue(char passager[20]);
	bool CanPushFirst();
	int getFirstQueueNum();
    void CancelFirstTicket(int x,int y);

	Seat addSecondPassager(char passager[20]);
	void pushSecondQueue(char passager[20]);
	bool CanPushSecond();
	int getSecondQueueNum();
    void CancelSecondTicket(int x,int y);

	Seat addThirdPassager(char passager[20]);
	void pushThirdQueue(char passager[20]);
	bool CanPushThird();
	int getThirdQueueNum();
    void CancelThirdTicket(int x,int y);

	void setFinalFlightNumber(int num);

    bool ifBookAgain(char passager[20]);
    
    void DeleteFirstQueue(char passager[20]);
    void DeleteSecondQueue(char passager[20]) ;
    void DeleteThirdQueue(char passager[20]) ;

};
