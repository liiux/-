#pragma once
#include<string>
#include"FlightID.h"

using namespace std;
class Passenger
{
public:
	Passenger();
	~Passenger();
    Passenger(const char*, const char*, const char*, const char*);
	void setPassenger(char* name, char* id, char* phonenum, char* passwork);
    void update_beforeFlight();
    void update_TicketsAssistantFlight();
    bool ifCanBook();
    void BookTicket(FlightID);
	bool TicketRefund(FlightID);
	void QueryTicket();
	void QueryTicketAssistant();
    //void AlterPassenger();//修改乘客信息
    friend Passenger FindPassenger(const char*);
    friend int InsertPassenger(Passenger someone);
	char* getName();
	char* getID();
	char* getPhoneNum();
	char* getPassword();
    int get_num_allFlight();
    int get_num_beforeFlight();
    int get_num_TicketsAssistant();
	FlightID* get_allFlight();
	FlightID* get_beforeFlight();
	FlightID* get_TicketsAssistant();
	void setName(char* );
	void setID(char* );
	void setPhoneNum(char*);
	void setPassword(char*);
	void set_allFlight(FlightID*);
	void set_beforeFlight(FlightID*);
	void set_TicketsAssistant(FlightID*);
    void set_num_allFlight(int);
    void set_num_beforeFlight(int);
	int show_now_num_of_passenger();
    void set_num_TicketsAssistant(int);
    friend void AlterPassenger(Passenger someone);
    void success_TicketsAssistant(FlightID);

private:
	char Name[20];
	char ID[20];
	char PhoneNum[20];
	char Password[20];
	FlightID allFlight[30];
	int num_allFlight;
	FlightID beforeFlight[5];
	int num_beforeFlight;
	FlightID TicketsAssistant[10];
	int num_TicketsAssistant;
};
