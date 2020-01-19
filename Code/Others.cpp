#include"Others.h"
void Copy_char(const char a[], char b[]) {
	int i = 0;
	for (; a[i] != '\0'; i++) {
		b[i] = a[i];
	}
	b[i] = '\0';
}//将字符数组a的值赋予b

bool ifRight(char s[])
{
    for(int i = 0; i < 17; i++){
        if(s[i] >=48 && s[i] <= 57)
            continue;
        else
            return false;
    }
    if(!((s[17] >= 48 && s[17] <= 57) || s[17] == 'x' || s[17] == 'X'))
        return false;
    return true;
}

cycleQueue::cycleQueue() {
	m_front = 0;
	m_rear = 0;
	num = 0;
}

void cycleQueue::Delete(char ele[20]) {
	int mark; int This = 0;
	if (m_rear > m_front) {
		for (int i = m_front; i < m_rear;i++) {
			if (strcmp(m_data[i], ele) == 0) {
				mark = i; This = 1; break;
			}
		}
		if (This == 1) {
			for (int i = mark; i < m_rear - 1; i++) {
				strcpy_s(m_data[i], m_data[i + 1]);
			}
			m_rear--; num--; return;
		}
	}
	if (m_rear < m_front) {
		for (int i = 0; i < m_rear; i++) {
			if (strcmp(m_data[i], ele) == 0) {
				mark = i; This = 1; break;
			}
		}
		if (This == 1) {
			for (int i = mark; i < m_rear - 1; i++) {
				strcpy_s(m_data[i], m_data[i + 1]);
			}
			m_rear = (m_rear - 1 + m_size) % m_size; num--; return;
		}
		for (int i = m_front; i < 21; i++) {
			if (strcmp(m_data[i], ele) == 0) {
				mark = i; This = 1; break;
			}
		}
		if (This == 1) {
			for (int i = mark; i > m_front; i--) {
				strcpy_s(m_data[i], m_data[i - 1]);
			}
			m_front = (m_front + 1) % m_size; num--; return;
		}
	}
}
bool cycleQueue::isFull() {
	return m_front == (m_rear + 1) % m_size;
}
bool cycleQueue::isEmpty() {
	return m_front == m_rear;
}
void cycleQueue::push(char ele[20]) {
	if (isFull()) {
		//如果队列是满的，通过界面显示不能预约订票
	}
    strcpy_s(m_data[m_rear], ele);
	m_rear = (m_rear + 1) % m_size;
	num++;
}
int cycleQueue::getNum() {
	return num;
}
char* cycleQueue::pop() {
	if (isEmpty()) {
		;//表示队列内已无等待乘客
	}
	else {
        strcpy_s(tmp, m_data[m_front]);
		m_front = (m_front + 1) % m_size;
		num--;
		return tmp;
	}
}

Seat::Seat() {}
Seat::Seat(int a, int b) {
	x = a; y = b;
	char s1[10];
	_itoa_s(a + 1, s1, 10);
	char s2[10];
	_itoa_s(b + 1, s2, 10);
	char s3[5] = "排";
	char s4[5] = "位";
	int i = 0;
	int j = 0;
	for (i = 0; s1[i] != '\0'; i++) {
		SeatString[j] = s1[i];
		j++;
	}
	for (i = 0; s3[i] != '\0'; i++) {
		SeatString[j] = s3[i];
		j++;
	}
	for (i = 0; s2[i] != '\0'; i++) {
		SeatString[j] = s2[i];
		j++;
	}
	for (i = 0; s4[i] != '\0'; i++) {
		SeatString[j] = s4[i];
		j++;
	}
	SeatString[j] = '\0';
}
char* Seat::showSeat() {
	return SeatString;
}
Seat & Seat:: operator =(Seat p) {
	x = p.x;
	y = p.y;
	Copy_char(p.SeatString, SeatString);
	return *this;
}
int Seat::getX() {
	return x;
}
int Seat::getY() {
	return y;
}
void Seat::Xadd() {
	x++;
}
void Seat::Yadd() {
	y++;
}
void Seat::YTo0() {
	y = 0;
}
Date::Date() {}
Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
Date::Date(const Date & p) {
	year = p.year;
	month = p.month;
	day = p.day;
}
Date & Date:: operator =(Date p) {
	year = p.year;
	month = p.month;
	day = p.day;
	return *this;
}
void Date::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
int Date::mycompare(Date time) {
	if (year > time.getYear()) { return 1; }
	if (year < time.getYear()) { return -1; }
	else {
		if (month > time.getMonth())return 1;
		if (month < time.getMonth())return -1;
		else {
			if (day > time.getDay())return 1;
			if (day < time.getDay())return -1;
			else {
				return 0;
			}
		}
	}
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}

Time::Time() {}
Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}
Time::Time(const Time & p) {
	hour = p.hour;
	minute = p.minute;
	second = p.second;
}
Time & Time::operator =(Time p) {
	hour = p.hour;
	minute = p.minute;
	second = p.second;
	return *this;
}
void Time::setTime(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}
int Time::getHour() {
	return hour;
}
int Time::getMinute() {
	return minute;
}
int Time::getSecond() {
	return second;
}
int Time::mycompare(Time time) {
	if (hour > time.getHour()) { return 1; }
	if (hour < time.getHour()) { return -1; }
	else {
		if (minute > time.getMinute())return 1;
		if (minute < time.getMinute())return -1;
		else {
			if (second > time.getSecond())return 1;
			if (second < time.getMinute())return -1;
			else {
				return 0;
			}
		}
	}
}

