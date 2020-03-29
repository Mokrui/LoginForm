#include<iostream>
#include"header.h"

using namespace std;

int main() {
	int choose = 0;
	do {
		system("cls");
		cout << "\tMENU" << endl;
		cout << "1. Registration" << endl;
		cout << "2. Login" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			reg();
			break;
		case 2:
			login();
			break;
		default:
			break;
		}

	} while (true);
}