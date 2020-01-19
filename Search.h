#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include"Others.h"
#include"Flight.h"
#include"index.h"
#include"Write.h"
#include"background.h"
#include<vector>
using namespace std;
#include<queue>
vector<Flight> Search(Date date, char Place1[30], char Place2[30]);
Flight SearchByFlightNumber(Date date, char FlightNumber[30]);
