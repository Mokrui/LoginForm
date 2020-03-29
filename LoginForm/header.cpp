#include "header.h"
#include<list>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

list<LoginData> LoginDatas;
const string FileName = "LoginData.txt";



void reg() {
	system("cls");
	string log = "";
	LoginData newdata;
	cout << "Enter login: ";
	cin >> log;

	bool logexist = false;
	for (auto it : LoginDatas) {
		if (it.login == log) {
			logexist = true;
		}
	}
	if (!logexist) {
		newdata.login = log;
		cout << "Enter password: ";
		cin >> newdata.password;

		//¬пихнуть
		//—юда

		//Ўифр
		//ѕаролей

		LoginDatas.push_back(newdata);

		ofstream fout;
		fout.open(FileName, fstream::app);

		bool isOpen = fout.is_open();
		if (!isOpen) {
			cout << "Error\n";
		}
		else {
			fout << newdata.login << " " << newdata.password << endl;
		}

		cout << "Registration comlepted!\n";
		system("pause");
	}
	else {
		cout << "Such user already exists\n";
		system("pause");
	}
}

void login(){
	string log = "";
	string pas = "";
	system("cls");
	cout << "Enter login: ";
	cin >> log;
	cout << "Enter password: ";
	cin >> pas;
	for (auto it : LoginDatas) {
		if (it.login == log && it.password == pas) {
			system("cls");
			cout << "Hello! " << it.login << endl;
		}
	}
}

void init()
{
	ifstream fin;
	fin.open(FileName);
	bool isOPen = fin.is_open();

	if (isOPen == false) {
		system("cls");
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		LoginData oldData;
		while (!fin.eof()) {
			currentString++;
			getline(fin, data);
			
			if (currentString == 1) {
				oldData.login = data;
			}
			else if(currentString == 2)
			{
				oldData.password = data;
				currentString = 0;
				LoginDatas.push_back(oldData);
				oldData = LoginData();
			}
		}
	}
	fin.close();

	//  encrypt(const string & s) {
	//	string temp(s);
	//	rotate(temp.begin(), temp.begin() + 2, temp.end());
	//	return temp;
	//}
	
	//string User::decrypt(const string & s) {
	//	if (s.empty()) {
	//		return s;
	//	}
	//	string tmp(s);
	//	rotate(tmp.begin(), tmp.begin() + tmp.size() - 2, tmp.end());
	//	return tmp;
	//}

}