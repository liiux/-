#include"Initialize.h"
bool MyCompare(string address1, int Y2, int M2, int D2) {
	char YY1[10];
    YY1[0] = address1[0];
    YY1[1] = address1[1];
    YY1[2] = address1[2];
    YY1[3] = address1[3];
	YY1[4] = '\0';
	char MM1[5];
    MM1[0] = address1[5];
    MM1[1] = address1[6];
	MM1[2] = '\0';
	char DD1[5];
    DD1[0] = address1[8];
    DD1[1] = address1[9];
	DD1[2] = '\0';
	int Y1 = atoi(YY1);
	int M1 = atoi(MM1);
	int D1 = atoi(DD1);
	if (Y1 < Y2) { return 1; }
	if (Y1 > Y2) { return 0; }
	else {
		if (M1 < M2) { return 1; }
		if (M1 > M2) { return 0; }
		else {
			if (D1 < D2) { return 1; }
			else {
				return 0;
			}
		}
	}
}
void getFiles0(vector<string>& files) {
    intptr_t Handle;
    struct _finddata_t FileInfo;
    if ((Handle = _findfirst("..\\航班信息\\*.dat", &FileInfo)) == -1L);
    //if ((Handle = _findfirst("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\*.dat", &FileInfo)) == -1L);
    else{


        do {
            string N = FileInfo.name;
            files.push_back(N);
        }while((_findnext(Handle, &FileInfo) == 0));
        _findclose(Handle);
    }
}


//应用程序初始化前，将航班信息内过期信息删除掉
void Initial() {
	time_t now = time(0);
	char dt[TIMESIZE];

	errno_t err;
	err = ctime_s(dt, TIMESIZE, &now);
	struct tm ltm;
	localtime_s(&ltm, &now);

	int year = 1900 + ltm.tm_year;
	int month = 1 + ltm.tm_mon;
	int day = ltm.tm_mday;
	vector<string> FileNames;

    getFiles0(FileNames);

    //getFiles("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息", FileNames);
	int s = FileNames.size();

	for (int i = 0; i < s; i++) {
        if (MyCompare(FileNames[i], year, month, day)) {
            string name = "..\\航班信息\\" + FileNames[i];
            //string name = "C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\" + FileNames[i];
            remove(name.c_str());
        }
	}


	/*char Y[10];
	char M[5];
	char D[5];
	_itoa_s(year, Y, 10);
	_itoa_s(month, M, 10);
	_itoa_s(day, D, 10);
	char address[50] = "";
	strcat_s(address, Y);
	strcat_s(address, "-");
	if (month < 10)strcat_s(address, "0");
	strcat_s(address, M);
	strcat_s(address, "-");
	if (day < 10)strcat_s(address, "0");
	strcat_s(address, D);
	strcat_s(address, ".dat");
	cout << address << endl;*/
}
