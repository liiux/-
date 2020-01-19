#include"index.h"
int calculatePages(const char Place1[30], const char Place2[30]) {
	int P1 = PlaceToNum(Place1);
	int P2 = PlaceToNum(Place2);
	if (P1 == 0 || P2 == 0) {
		//此处跳转界面，无搜索航班
        return -1;
	}
	if (P1 == P2) {
		//这是出发机场和降落机场都是一个机场的情况，不符合实际
	}
	if (P1 < P2) {
		return (P1 - 1) * 197 + P2 - 2;
	}
	if (P1 > P2) {
		return (P1 - 1) * 197 + P2 - 1;
	}
}
void WriteIndex(char address[100]) {
	fstream f;
	f.open(address, ios::out | ios::in | ios::binary);
	int i, j;
	int airportNum = 198;
	for (i = 1; i <= airportNum; i++) {
		for (j = 1; j <= airportNum; j++) {
			if (j == i)continue;
			IndexPoint ip;
			ip.ifWrite = 0;
			ip.number = 0;
			for (int i = 0; i < 10; i++) {
				ip.position[i] = 0;
			}
			ip.Max = -1;
			ip.startNum = i;
			ip.endNum = j;
			f.write((char*)&ip, sizeof(IndexPoint));
		}
	}
	f.close();
}
