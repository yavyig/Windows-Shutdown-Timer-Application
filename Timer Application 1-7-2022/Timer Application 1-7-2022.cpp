/*
WRITTEN BY YAVUZ ALPER YIGITOGLU
ON 2022-01-07
*/
#include <iostream>
#include <Windows.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

void clear() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}

int main() {
	int hh = 0, mm = 0, ss = 0;
	cout << "WARNING: If you input an hour value greater than 99999 it will shutdown your computer immediately!" << endl;
		cout << "Set the timer (hh:mm:ss): ";
	cin >> hh;
	if (cin.peek() == ':')cin.ignore();
	cin >> mm;
	if (cin.peek() == ':')cin.ignore();
	cin >> ss;

	while (hh > 0) {
		hh--;
		mm += 60;
	}
	while (mm > 0) {
		mm--;
		ss += 60;
	} //all in seconds now

	while (ss > 0) {
		Sleep(1000); //means one second
		clear();
		cout << "==========================" << endl;
		cout << "= WINDOWS SHUTDOWN TIMER =" << endl;
		cout << "==========================" << endl << endl;

		cout << "Your computer will shutdown in " << --ss << " seconds\n";

		int temphh = 0, tempmm = 0, tempss = 0,tempdd=0,tempmonth=0,tempyy=0;
		tempss = ss % 60;
		tempmm = (ss / 60) % 60;
		temphh = (ss / 3600)%24;
		tempdd = (ss / 86400)%30;
		tempmonth = (ss / 2628288) % 12;
		tempyy = ss / 31536000;

	//	cout << setfill('0') << setw(2) << right << temphh << ':' << setw(2) << right << tempmm << ':' << setw(2) << right << tempss << endl<<endl;

		if (tempyy > 0) {
			cout << tempyy<< " years, " << tempmonth << " months, " << tempdd << " days, " << temphh << " hours, " << tempmm << " minutes, " << tempss << " seconds." << endl;
		}
		else if (tempmonth > 0) {
			cout << tempmonth <<" months, " << tempdd << " days, " << temphh << " hours, " << tempmm << " minutes, " << tempss << " seconds." << endl;
		}
		else if (tempdd > 0) {
			cout << tempdd << " days, " << temphh << " hours, " << tempmm << " minutes, " << tempss << " seconds." << endl;
		}
		else if (temphh > 0) {
			cout << temphh << " hours, " << tempmm << " minutes, " << tempss << " seconds." << endl;
		}
		else if (tempmm > 0) {
			cout << tempmm << " minutes, " << tempss << " seconds." << endl;
		}
		else {
			cout << tempss << " seconds." << endl;
		}
	

	}
	system("C:\\Windows\\System32\\shutdown /s /t 0"); //shutdowns the pc immediately

	return 0;
};