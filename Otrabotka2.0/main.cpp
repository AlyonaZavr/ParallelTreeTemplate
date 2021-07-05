#include <iostream>
#include<string>
#include "func.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	string first, second, result;
	vector<char> letterarr;
	first = "aa";
	second = "aa";
	result = "bbaa";
	cout << "ребус: " << first << " * " << second << " = " << result << endl;
	//ABC(letterarr, first, second, result);

	vector<int> v(3, -1);
	//cout << v.size() << endl;
	podbor(0, v);
	/*for (int i = 0; i < 5; i++)
		cout << podbor(0, v)[i] << endl;*/
	return 1;
}