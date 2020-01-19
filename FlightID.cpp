#include "FlightID.h"
#include "Others.h"
FlightID::FlightID()
{

}

FlightID::FlightID(char sp[20], char ep[20], char f[20], char p[20], Date d, Time st, Time et, int l, int r, int c, int pp){
    for(int i=0; i<20; i++){
        StartPlace[i] = sp[i];
        EndPlace[i] = ep[i];
        FlightNumber[i] = f[i];
        PlaneNumber[i] = p[i];
    }
    int yy, mm, dd;
    yy = d.getYear();
    mm = d.getMonth();
    dd = d.getDay();
    DepartureDate.setDate(yy, mm, dd);
    int sth, stm, sts, eth, etm, ets;
    sth = st.getHour();
    stm = st.getMinute();
    sts = st.getSecond();
    eth = et.getHour();
    etm = et.getMinute();
    ets = et.getSecond();
    StartTime.setTime(sth, stm, sts);
    EndTime.setTime(eth, etm, ets);
    Level = l;
    Seat_row = r;
    Seat_colume = c;
    price = pp;
}

char* FlightID::getStartPlace(){
    return StartPlace;
}
char* FlightID::getEndPlace(){
    return EndPlace;
}
char* FlightID::getFlightNumber(){
    return FlightNumber;
}
char* FlightID::getPlaneNumer(){
    return PlaneNumber;
}
Date FlightID::getDepartureDate(){
    return DepartureDate;
}
Time FlightID::getStartTime(){
    return StartTime;
}
Time FlightID::getEndTime(){
    return EndTime;
}
int FlightID::getLevel(){
    return Level;
}
int FlightID::getSeat_row(){
    return Seat_row;
}
int FlightID::getSeat_colume(){
    return Seat_colume;
}
int FlightID::getPrice(){
    return price;
}

void FlightID::setStartPlace(char s[20]){
    for(int i=0;i<20;i++)
        StartPlace[i] = s[i];
}
void FlightID::setEndPlace(char e[20]){
    for(int i=0;i<20;i++)
        EndPlace[i] = e[i];
}
void FlightID::setFlightNumber(char f[20]){
    for(int i=0;i<20;i++)
        FlightNumber[i] = f[i];
}
void FlightID::setPlaneNumer(char p[20]){
    for(int i=0;i<20;i++)
        PlaneNumber[i] = p[i];
}
void FlightID::setDepartureDate(Date d){
    int yy, mm, dd;
    yy = d.getYear();
    mm = d.getMonth();
    dd = d.getDay();
    DepartureDate.setDate(yy, mm, dd);
}
void FlightID::setStartTime(Time st){
    int sth, stm, sts;
    sth = st.getHour();
    stm = st.getMinute();
    sts = st.getSecond();
    StartTime.setTime(sth, stm, sts);
}
void FlightID::setEndTime(Time et){
    int eth, etm, ets;
    eth = et.getHour();
    etm = et.getMinute();
    ets = et.getSecond();
    EndTime.setTime(eth, etm, ets);
}
void FlightID::setLevel(int l){
    Level = l;
}
void FlightID::setSeat_row(int r){
    Seat_row = r;
}
void FlightID::setSeat_colume(int c){
    Seat_colume = c;
}
void FlightID::setPrice(int p){
    price = p;
}

bool FlightID::ifbefore(){
    QDate currentdate;
    QTime currenttime;
    currentdate = QDate::currentDate();
    currenttime = QTime::currentTime();
    QDate mydate(DepartureDate.getYear(), DepartureDate.getMonth(), DepartureDate.getDay());
    QTime mytime(StartTime.getHour(), StartTime.getMinute(), StartTime.getSecond());
    if(mydate < currentdate){
        return true;
    }
    else if(mydate == currentdate){
        if(mytime < currenttime){
            return true;
        }
    }
    return false;
}

bool FlightID::equalTo(FlightID fid)
{
    if(DepartureDate.mycompare(fid.getDepartureDate())==0&&strcmp(FlightNumber, fid.getFlightNumber())==0)
        return true;
    return false;
}
