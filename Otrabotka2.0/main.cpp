#include <iostream>
#include<string>
#include "func.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	string first, second, result;
	first = "ab";
	second = "cab";
	result = "cab";
	cout << "ребус: " << first << " * " << second << " = " << result << endl;
	ABC(first, second, result);
	cout << "больше решений нет" << endl;
	return 1;
}