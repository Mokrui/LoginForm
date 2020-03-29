#pragma once
#include<string>
#include<iostream>
using namespace std;

struct LoginData {
	string login;
	string password;
};

void login();
void reg();
void init();