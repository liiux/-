#pragma once
#include"background.h"
#include"Others.h"
#include"index.h"
#include <QProgressBar>
using namespace std;
#include<fstream>
#include"Flight.h"
void WriteOne(char address[100], Flight flight);
void Write(Date date, Flight flight);
void WriteTT(Date date, QProgressBar* qp);
