#include <iostream>			// ��������� � ���������� ����� �����������!!!
#include <fstream>			// VERSION 1 DOWNLOAD:"Library2"; REMOVE:"Library" + ������� updater!!
#include <cstring>
#include <cctype>
#include <urlmon.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <Windows.h>
#pragma comment(lib, "urlmon.lib")
using namespace std;

bool getconchar(KEY_EVENT_RECORD& krec) {
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL) {
		return false; // console not found
	}

	for (;;) {
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)//&& ! ((KEY_EVENT_RECORD&)irec.Event).wRepeatCount )
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false; //future ????
}
//GOD DAMN MAGIC!


void updater() {
	URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1qPvN56Dy5mZeoQAHQS5ZMZCC2PyheCNo", "versionHost.txt", 0, 0); //version of file
	ofstream fHere("version.ini");
	fstream fHost("versionHost.txt");
	if (!fHere.is_open() || !fHost.is_open()) {
		cout << "���������� �������� ���������!";
		Sleep(1500);
		exit(0);
	}

	char *newName = new char[40];
	char *newV = new char[10];
	fHost.getline(newV, 40);
	fHost.getline(newName, 40);
	fHere << newV;
	URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1n_487YAWCcN4hXEh360JN8MVYCBAKym9", newName, 0, 0); //file
	cout << "done!";

	fHere.close();
	fHost.close();
	delete[]newName;
	remove("versionHost.txt");
	cout << endl << "������, �������� ����� ������";

	Sleep(1000);
	exit(0);
}

int checkVersion(bool &update) {
	char *version = new char[10];
	char *versionHost = new char[10];
	string ver, verHost;

	cout << "�������� ������ ���������..." << endl;
	ifstream f("version.ini");
	if (!f.is_open()) {
		cout << "��� ��������� ������";
		Sleep(1500);
		return 0;
	}
	cout << "���������� � ��������... " << endl << endl;
	try {
		URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1qPvN56Dy5mZeoQAHQS5ZMZCC2PyheCNo", "versionHost.txt", 0, 0);
	}
	catch (exception ex) {
		cout << "��� ���������� � ����������";
		return 0;
	}

	ifstream fHost("versionHost.txt");
	f.getline(version, 10);
	fHost.getline(versionHost, 10);
	ver = version;
	verHost = versionHost;
	if (ver == verHost) cout << "�������� ��������� ������!";
	else {
		update = true;
		cout << "�������� ������";
	}
	Sleep(1000);

	f.close();
	fHost.close();
	remove("versionHost.txt");
	delete[]version;
	delete[]versionHost;
	return 0;
}

char *toLower(char *aa) {					//� ������ �������
	char kek;
	for (int i = 0; i < strlen(aa); i++) {
		kek = aa[i];
		aa[i] = (char)tolower(kek);
	}
	return aa;
}

void helpFind(string &string) {
	string.erase(remove(string.begin(), string.end(), ' '), string.end());
	string.erase(remove(string.begin(), string.end(), '.'), string.end());
	string.erase(remove(string.begin(), string.end(), ','), string.end());
	string.erase(remove(string.begin(), string.end(), ':'), string.end());
	string.erase(remove(string.begin(), string.end(), ';'), string.end());
	string.erase(remove(string.begin(), string.end(), '"'), string.end());
	string.erase(remove(string.begin(), string.end(), '\''), string.end());
}

int find() {
	int uk = 1;
	fstream f("sys.txt");
	if (!f.is_open()) {
		cout << "��������� ��������� ������!";
	}
	char *findID = new char[101];
	char *findAvt = new char[101];
	char *findName = new char[101];
	char *findMesto = new char[101];
	char *find = new char[101];
	cout << "������� ����� ���������� � �����: ";
	//cin.getline(find, 100);		//�� �������!!! ����� ����������� ����!!! // ��� �������???

	//BEGIN HELL

	cin.getline(find, 100);
	OemToCharA(find, find);
	toLower(find);
	string ff = toLower(find);

	helpFind(ff);

	cout << "����� �� ������� " << find << endl;

	while (!f.eof()) {
		f.getline(findID, 100);
		string fflibID = toLower(findID);
		f.getline(findAvt, 100);
		string fflibAvt = toLower(findAvt);
		f.getline(findName, 100);
		string fflibName = toLower(findName);
		f.getline(findMesto, 100);
		string fflibMesto = toLower(findMesto);

		helpFind(fflibAvt);
		helpFind(fflibName);
		helpFind(fflibMesto);

		if (ff == fflibAvt || ff == fflibName || ff == fflibMesto || ff == fflibID) {
			cout << uk << ": ";
			cout << "����� �����: " << findID << endl;
			cout << "�����: " << findAvt << endl;
			cout << "��������: " << findName << endl;
			cout << "��������������: " << findMesto << endl << endl;
			uk++;
		}
	}

	//END HELL

	f.close();
	delete[]findID;
	delete[]findAvt;
	delete[]findName;
	delete[]findMesto;
	delete[]find;

	return 0;
}

int betaFind() {
	int uk = 1;
	fstream f("sys.txt");
	if (!f.is_open()) {
		cout << "��������� ��������� ������!";
	}
	char *findID = new char[101];
	char *findAvt = new char[101];
	char *findName = new char[101];
	char *findMesto = new char[101];
	char *find = new char[101];
	cout << "������� ����� ���������� � �����: ";
	//cin.getline(find, 100);		//�� �������!!! ����� ����������� ����!!! // ��� �������???

	//BEGIN HELL

	cin.getline(find, 100);
	OemToCharA(find, find);
	toLower(find);
	string ff = toLower(find);

	helpFind(ff);

	cout << "����� �� ������� " << find << endl;

	while (!f.eof()) {
		f.getline(findID, 100);
		string fflibID = toLower(findID);
		f.getline(findAvt, 100);
		string fflibAvt = toLower(findAvt);
		f.getline(findName, 100);
		string fflibName = toLower(findName);
		f.getline(findMesto, 100);
		string fflibMesto = toLower(findMesto);

		helpFind(fflibAvt);
		helpFind(fflibName);
		helpFind(fflibMesto);

		if (fflibAvt.find(ff) || fflibName.find(ff) || fflibMesto.find(ff)) {
			cout << uk << ": ";
			cout << "����� �����: " << findID << endl;
			cout << "�����: " << findAvt << endl;
			cout << "��������: " << findName << endl;
			cout << "��������������: " << findMesto << endl << endl;
			uk++;
		}
	}

	//END HELL

	f.close();
	delete[]findID;
	delete[]findAvt;
	delete[]findName;
	delete[]findMesto;
	delete[]find;

	return 0;
}

int helpIN(int &quan) {
	char *ID = new char[100];
	ifstream f("sys.txt");
	while (!f.eof()) {
		f.seekg(f.tellg());
		f.getline(ID, 100);
	}
	f.close();
	quan = atoi(ID);
	return quan;
}

int in() {
	int quantity;
	helpIN(quantity);
	char *author = new char[100];
	char *name = new char[100];
	char *place = new char[100];
	ifstream fhelp;
	fhelp.open("sys.txt");
	if (!fhelp.is_open()) {
		cout << "��������� ��������� ������!";
		Sleep(1500);
	}
	fhelp.close();
	fstream f("sys.txt", ios_base::app);
	if (!f.is_open()) {
		cout << "��������� ��������� ������!";
		Sleep(1500);
	}

	//BEGIN WRITE

	cout << "������� ��� ������: " << endl;
	cin.getline(author, 100);
	//cin.getline(author, 100);  // �� �������, ����� �� ��������!!
	cout << endl << "������� �������� �����: " << endl;
	cin.getline(name, 100);
	cout << endl << "������� ��������������: " << endl;
	cin.getline(place, 100);
	OemToCharA(author, author);
	OemToCharA(name, name);
	OemToCharA(place, place);

	f << endl << author << endl << name << endl << place << endl << quantity + 1;

	//END WRITE

	f.close();
	fhelp.close();
	delete[]author;
	delete[]name;
	delete[]place;
	return 0;
}

int out() {
	cout << "����� ������� ��� �����? ��� ������ ��������� �����" << endl;
	cout << "1 - ��, �������" << endl;
	cout << "2 - ���, �� �����" << endl;
	int check;
	cin >> check;
	if (check == 1) {
		system("cls");
		cout << "��, ���: " << endl << endl;

		char *a = new char[151];
		ifstream f;
		f.open("sys.txt");
		if (!f.is_open()) {
			fstream fWrite("sys.txt", ios_base::out);
			fWrite << "1";
			fWrite.close();
		}

		while (!f.eof()) {
			f.seekg(f.tellg());
			f.getline(a, 150);
			cout << a << endl;
		}

		f.close();
		delete[]a;
		return 0;
	}
	else return 0;
}

int action(bool update) {
	KEY_EVENT_RECORD key;
	cout << "������!" << endl;
	while (true) {
		if (update) cout << "0 - �������� ���������" << endl;
		cout << endl;
		cout << "1 - �����" << endl;
		cout << "2 - ��������" << endl;
		cout << "3 - ������� ���" << endl;
		cout << "8 - ���� �����" << endl;
		cout << "4 - �����" << endl;
		cout << "5 - ����" << endl;
		cout << "�������� ��������: " << " ";
		getconchar(key);
		switch (key.uChar.AsciiChar) {
		case '0': if (update) updater();
			system("cls");
			break;
		case '1': system("cls"); find();
			break;
		case '2': system("cls"); in();
			break;
		case '3': system("cls"); out();
			break;
		case '8': system("cls"); betaFind();
			break;
		case '4': system("cls"); return 0;
			break;
		case '5': system("cls"); cout << endl << "��� ������������ ���������, ���������� �� ����� C++(17)\n";
			//cout << endl << "P.S. ���� ���� ������� �����, ������ �������� �� a.m.popugaev@gmail.com" << endl;
			cout << "'���� �����' - ����� � �������� ������, ��� �� ������� ������ ���������� ������ ����; ������������ �� �������������!\n";
			cout << "UPD 1.35 (17.05) ��������������� �����, ���� �����(������ ���� �� �������); �������� ������ �������" << endl;
			break;
		default:
			system("cls");

		}
	}
}

int systemFiles() {
	//check version.ini
	ifstream f("version.ini");
	if (!f.is_open()) {
		f.close();
		fstream fWrite("version.ini", ios_base::out);
		fWrite << "1.0";
		fWrite.close();
	}
	f.close();

	//check sys.txt

	ifstream fhelp("sys.txt");
	if (!fhelp.is_open()) {
		fstream fWrite("sys.txt", ios_base::out);
		fWrite << "1";
		fWrite.close();
	}
	fhelp.close();

	//deletePrevious versions

	//remove("Library.exe");
	//remove("Library2.exe");
	//remove("Library_1.11.exe");
	//remove("Library_1.2.exe");

	return 0;
}

int main() {									//MAIN
	systemFiles();
	setlocale(LC_CTYPE, "Russian");

	bool update = false;
	checkVersion(update);
	system("cls");
	action(update);

	cout << "END";
	return 0;
}