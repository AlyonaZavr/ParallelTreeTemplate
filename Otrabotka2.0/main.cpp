#include <iostream>
#include<string>
#include "func.h"
#include <fstream>;
using namespace std;

int main()
{
	unsigned int start_time = clock();
	setlocale(LC_ALL, "Rus");
	vector<string> str;
	string first, second, result;
	ifstream fin("test.txt");
	for (int i = 0; i < 4; i++)
	{
		if (!fin.is_open()) { cout << "Error!" << endl; }
		else
		{
			fin >> first;
		}
		if (!fin.is_open()) { cout << "Error!" << endl; }
		else
		{
			fin >> second;
		}
		if (!fin.is_open()) { cout << "Error!" << endl; }
		else
		{
			fin >> result;
		}
		cout << "ребус: " << first << " * " << second << " = " << result << endl;
		if (ABC(str, first, second, result))
		{
			if (str.empty()) {
				cout << "решений нет!" << endl;
			}
			else
			{
				for (int i = 0; i < str.size(); i++)
					cout << str[i] << endl;
				cout << "больше решений нет" << endl;
			}
		}
		else
			cout << "колличество букв превышает колличество цифр!" << endl;
		unsigned int end_time = clock();
		cout << "search_time: " << (end_time - start_time) / 1000. << endl;
		cout << "-------------------------------" << endl;
	}
	return 1;
}