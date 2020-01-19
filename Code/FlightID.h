#ifndef FLIGHTID_H
#define FLIGHTID_H

#include "Others.h"
#include <QDate>
#include <QTime>

class FlightID
{
public:
    FlightID();
    FlightID(char[20], char[20], char[20], char[20], Date, Time, Time, int, int, int, int);
    char* getStartPlace();
    char* getEndPlace();
    char* getFlightNumber();
    char* getPlaneNumer();
    Date getDepartureDate();
    Time getStartTime();
    Time getEndTime();
    int getLevel();
    int getSeat_row();
    int getSeat_colume();
    int getPrice();

    void setStartPlace(char[20]);
    void setEndPlace(char[20]);
    void setFlightNumber(char[20]);
    void setPlaneNumer(char[20]);
    void setDepartureDate(Date);
    void setStartTime(Time);
    void setEndTime(Time);
    void setLevel(int);
    void setSeat_row(int);
    void setSeat_colume(int);
    void setPrice(int);
    bool  ifbefore();
    bool equalTo(FlightID);
private:
    char StartPlace[20];
    char EndPlace[20];
    char FlightNumber[20];
    char PlaneNumber[20];
    Date DepartureDate;
    Time StartTime;
    Time EndTime;
    int Level;
    int Seat_row;//行
    int Seat_colume;//列
    int price;

};

#endif // FLIGHTID_H
