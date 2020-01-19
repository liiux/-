#include"Passenger.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
using namespace std;

bool equalToChar(const char a[20], const char b[20])
{
	for (int i = 0; i < 18; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}




const Passenger markEnd("000", "000000000000000000", "000", "000");
const Passenger markEmpty("000", "111111111111111111", "000", "000");


int h(const char id[20])
{
	return ((id[9] - '0') * 100000 + (id[13] - '0') * 10000 + (id[16] - '0') * 1000
		+ (id[0] - '0' + id[1] - '0' + id[2] - '0') % 10 * 100
		+ (id[11] - '0') * 10 + (id[4] - '0' + id[5] - '0') % 10) % 400000;
}

int InsertPassenger(Passenger someone)
{
	int currcnt;//当前哈希表中存放乘客数
	fstream ffff;
    ffff.open("..\\PassengerTest.dat", ios::out | ios::in | ios::binary);
    //ffff.open("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\PassengerTest.dat", ios::out | ios::in | ios::binary);
	ffff.seekg(0, ios::beg);
	ffff.read((char*)&currcnt, sizeof(int));
	if (currcnt >= 400000)
	{
        //cout << "哈希表已满" << endl;
		ffff.close();
        return 1;
	}
	int home;
	int pos = home = h(someone.ID);
	Passenger tem;
	ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
	ffff.read((char*)&tem, sizeof(Passenger));
	for (int i = 1; (i <= 10000) && (!equalToChar(tem.ID, markEmpty.ID)); i++)
	{
		pos = (home + i*i) % 400000;
		if (equalToChar(someone.ID, tem.ID))
		{
            //cout << "重复关键字" << endl;
			ffff.close();
            return 2;
		}
		ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
		ffff.read((char*)&tem, sizeof(Passenger));
	}
	if (!equalToChar(tem.ID, markEmpty.ID))//EMPTYKEY != (HT[pos]).key())
	{
        //QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("插入失败"));
        //cout << "插入失败" << endl;
        ffff.close();
        return 3;
	}
	ffff.seekp(80 + pos * sizeof(Passenger), ios::beg);
	ffff.write((char*)&someone, sizeof(Passenger));
	ffff.seekp(0, ios::beg);
	currcnt++;
	ffff.write((char*)&currcnt, sizeof(int));
	ffff.close();
    return 4;
}

Passenger FindPassenger(const char* id)
{
	fstream ffff;
    ffff.open("..\\PassengerTest.dat", ios::out | ios::in | ios::binary);
    //ffff.open("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\PassengerTest.dat", ios::out | ios::in | ios::binary);
	int home;
	int pos = home = h(id);
	Passenger tem;
	ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
	ffff.read((char*)&tem, sizeof(Passenger));
	for (int i = 1; (!equalToChar(tem.ID, markEmpty.ID)) && (i <= 10000) && (!equalToChar(id, tem.ID)); i++)
	{
		pos = (home + i*i) % 400000;
		ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
		ffff.read((char*)&tem, sizeof(Passenger));
	}
	if (equalToChar(id, tem.ID))
	{
		ffff.close();
		return tem;
	}
	else
	{
        //cout << "查找失败，关键字不存在" << endl;
		ffff.close();
		return markEnd;
	}
}

Passenger::Passenger()
{
}

Passenger::~Passenger()
{
}

Passenger::Passenger(const char* name, const char* id, const char* phonenum, const char* passwork)
{
	for (int i = 0; i < 20; i++)
	{
		Name[i] = name[i];
		ID[i] = id[i];
		PhoneNum[i] = phonenum[i];
		Password[i] = passwork[i];
	}
	num_allFlight = 0;
	num_beforeFlight = 0;
	num_TicketsAssistant = 0;
}

void Passenger::setPassenger(char* name, char* id, char* phonenum, char* password)
{
	setName(name);
	setID(id);
	setPhoneNum(phonenum);
	setPassword(password);
	num_allFlight = num_beforeFlight = num_TicketsAssistant = 0;
}

char* Passenger::getName()
{
	return Name;
}

char* Passenger::getID()
{
	return ID;
}

char* Passenger::getPhoneNum()
{
	return PhoneNum;
}

char* Passenger::getPassword()
{
	return Password;
}

FlightID* Passenger::get_allFlight()
{
	return allFlight;
}

FlightID* Passenger::get_beforeFlight()
{
	return beforeFlight;
}

FlightID* Passenger::get_TicketsAssistant()
{
	return TicketsAssistant;
}

void Passenger::setName(char* n)
{
	for (int i = 0; i < 20; i++)
	{
		Name[i] = n[i];
	}
}

void Passenger::setID(char* id)
{
	for (int i = 0; i < 20; i++)
	{
		ID[i] = id[i];
	}
}

void Passenger::setPhoneNum(char* pn)
{
	for (int i = 0; i < 20; i++)
	{
		PhoneNum[i] = pn[i];
	}
}

void Passenger::setPassword(char* pw)
{
	for (int i = 0; i < 20; i++)
	{
		Password[i] = pw[i];
	}
}

void Passenger::set_allFlight(FlightID* aF)
{
	for (int i = 0; i < 30; i++)
	{
		allFlight[i] = aF[i];
	}
}

void Passenger::set_beforeFlight(FlightID* bF)
{
	for (int i = 0; i < 5; i++)
	{
		beforeFlight[i] = bF[i];
	}
}

void Passenger::set_TicketsAssistant(FlightID* tA)
{
	for (int i = 0; i < 10; i++)
	{
		TicketsAssistant[i] = tA[i];
	}
}

int Passenger::show_now_num_of_passenger()
{
	int currcnt;
	fstream ffff;
    ffff.open("..\\PassengerTest.dat", ios::out | ios::in | ios::binary);
    //ffff.open("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\PassengerTest.dat", ios::out | ios::in | ios::binary);
	ffff.seekg(0, ios::beg);
	ffff.read((char*)&currcnt, sizeof(int));
	ffff.close();
	return currcnt;
}

int Passenger::get_num_allFlight()
{
    return num_allFlight;
}

int Passenger::get_num_beforeFlight()
{
    return num_beforeFlight;
}

void Passenger::set_num_allFlight(int num_af)
{
    num_allFlight = num_af;
}

void Passenger::set_num_beforeFlight(int num_bf)
{
    num_beforeFlight = num_bf;
}

bool Passenger::ifCanBook()
{
    if (num_beforeFlight >= 5)
    {
        //"注意！一人最多可预定5班未起飞航班。请待其他航班起飞后再进行预定"
        return false;
    }
    else
    {
        return true;
    }
}

void Passenger::BookTicket(FlightID flight_id)
{
    if (num_allFlight == 30)
    {
        for (int i = 1; i < num_allFlight; i++)
        {
            allFlight[i - 1] = allFlight[i];
        }
        num_allFlight--;
    }
    allFlight[num_allFlight++] = flight_id;
    beforeFlight[num_beforeFlight++] = flight_id;
    cout << "订票成功！您的座位号是：" << flight_id.getSeat_row()
        << "行" << flight_id.getSeat_colume() << "列" << endl;
}

void Passenger::update_TicketsAssistantFlight()
{

    int i;
    int k=0;
    FlightID a[10];
    for (i = 0; i < num_TicketsAssistant; i++)
    {
        if (!TicketsAssistant[i].ifbefore())//判断是否起飞，起飞则进入if
        {
            a[k++]=TicketsAssistant[i];
        }
    }
    for(int h=0;h<k;h++)
    {
        TicketsAssistant[h]=a[h];
    }
    num_TicketsAssistant=k;
}

void Passenger::success_TicketsAssistant(FlightID fid)
{
    FlightID a[10];
    int k=0;
    for(int i=0;i<num_TicketsAssistant;i++)
    {
        if(!TicketsAssistant[i].equalTo(fid))
            a[k++]=TicketsAssistant[i];
    }
    for(int i=0;i<k;i++)
    {
        TicketsAssistant[i]=a[i];
    }
    num_TicketsAssistant=k;
}

void Passenger::update_beforeFlight()
{
    int i;
    int k=0;
    FlightID a[5];
    for (i = 0; i < num_beforeFlight; i++)
    {
        if (!beforeFlight[i].ifbefore())//判断是否起飞，起飞则进入if
        {
            a[k++]=beforeFlight[i];
        }
    }
    for(int h=0;h<k;h++)
    {
        beforeFlight[h]=a[h];
    }
    num_beforeFlight=k;
}


void initial()
{
    ofstream output("..\\PassengerTest.dat", ios::out | ios::binary);
    //ofstream output("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\PassengerTest.dat", ios::out | ios::binary);
	if (!output)
	{
		cerr << "Open output file error!" << endl;
		exit(-1);
	}
	output.seekp(0);
	int mm = 0;
	output.write((char *)&mm, sizeof(int));
	int i;
	for (i = 0, output.seekp(80, ios::beg); i < 400000; i++)
	{
		output.write((char*)&markEmpty, sizeof(Passenger));
	}
	output.write((char*)&markEnd, sizeof(Passenger));
	output.close();
}

void Passenger::set_num_TicketsAssistant(int num_ta)
{
    num_TicketsAssistant = num_ta;
}

int Passenger::get_num_TicketsAssistant()
{
    return num_TicketsAssistant;
}



void AlterPassenger(Passenger someone)
{
    fstream ffff;
    ffff.open("..\\PassengerTest.dat", ios::out | ios::in | ios::binary);
    //ffff.open("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\PassengerTest.dat", ios::out | ios::in | ios::binary);
    int home;
    int pos = home = h(someone.getID());
    Passenger tem;
    ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
    ffff.read((char*)&tem, sizeof(Passenger));
    for (int i = 1; (!equalToChar(tem.ID, markEmpty.ID)) && (i <= 10000) && (!equalToChar(someone.getID(), tem.ID)); i++)
    {
        pos = (home + i*i) % 400000;
        ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
        ffff.read((char*)&tem, sizeof(Passenger));
    }
    if (equalToChar(someone.getID(), tem.ID))
    {
        ffff.seekg(80 + pos * sizeof(Passenger), ios::beg);
        ffff.write((char*)&someone, sizeof(Passenger));
        ffff.close();
    }
    else
    {
        cout << "修改失败！！" << endl;
        ffff.close();
    }
}

