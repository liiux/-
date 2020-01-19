#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<io.h>
#include<vector>
#include"Others.h"
#include"Flight.h"
#include<time.h>
#include"index.h"
#include<direct.h>
#include"Write.h"
#include"background.h"

#define TIMESIZE 26

bool MyCompare(string address1, int Y2, int M2, int D2);

void getFiles0(vector<string>& files);

//应用程序初始化前，将航班信息内过期信息删除掉
void Initial();
