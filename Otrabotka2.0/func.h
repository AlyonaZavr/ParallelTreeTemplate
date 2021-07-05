#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> podbor(int index, vector<int> numberarr)//, vector<int> abc)
{
	bool k = 1;
	//vector<int> v(numberarr.size(),-1);
	//if (index < numberarr.size())
		for (int i = 0; i < 10; i++)
		{
			/*for (int j = 0; j < index; j++)
			{
				if (i = numberarr[j])
					k = 0;
			}
			
			if (k)*//*if (index < numberarr.size())
			{
				cout << index << endl;
				numberarr[index] = i;
				podbor(index + 1, numberarr);
			}
			else
	return numberarr;*/
			cout << index << endl;
			if (index = numberarr.size())
			{
				cout << index<<"HBJNBHJNB" << endl;
				numberarr[index] = i;
				return numberarr; 
			}
			else
			{
				cout << index <<"eb" << endl;
				numberarr[index] = i;
				podbor(index + 1, numberarr);
			}
		}
	/*for (int i = 0; i < numberarr.size(); i++)
		cout << numberarr[i];
	cout << endl; */
	//if (check(numberarr, abc))
	// 	   {
	//      for (int i = 0; i < numberarr.size(); i++)
	//           cout << numberarr[i];
	//           cout << endl;
	//      ?podbor(0, vector<int> v);
	//      } 

	

}

bool ABC(vector<char> abcd, string first, string second, string result)//составляет алфавит множества(на выходе строка) дабы сопоставить его с цифрами методом подборы
{
	int i = 0;
	string abc = first + second + result;
	while (i < abc.size() - 1)
	{
		int j = i + 1;
		while(j < abc.size())
		{
			if (abc[i] == abc[j])
				abc.replace(j, 1, "");
			else
				j++;
		}
		i++;
	}
	if (abc.size() > 10)
		return 0;
	cout <<"алфавит данного ребуса: "<<abc << endl;
	for (int i = 0; i < abc.size(); i++)
		abcd.push_back(abc[i]);
	return 1;
}



//bool(check)
/*int check(vector<letter> letterarr, string first, string second, string result) //проверка на то подходят ли выбранные цифры данному примеру
{
	//for (int i = 0; i < letterarr.size(); i++)
	//{
	//	cout << letterarr[i].c << " "<< letterarr[i].v<<", ";
	//}
	//cout << "++"<<endl;

	int val1 = 0, val2 = 0, val3 = 0, i, j, m = 1;
	int count = letterarr.size();
	for (i = first.size() - 1; i >= 0; i--)
	{
		char ch = first[i];
		for (j = 0; j < count; j++)
			if (letterarr[j].c == ch)
				break;
		val1 += m * letterarr[j].v;
		m *= 10;
		//cout << val1 << " ";
	}
	//cout << "---"<<endl;

	m = 1;

	for (i = second.size() - 1; i >= 0; i--)
	{
		char ch = second[i];
		for (j = 0; j < count; j++)
			if (letterarr[j].c == ch)
				break;
		val2 += m * letterarr[j].v;
		m *= 10;
	}

	m = 1;

	for (i = result.size() - 1; i >= 0; i--)
	{
		char ch = result[i];
		for (j = 0; j < count; j++)
			if (letterarr[j].c == ch)
				break;
		val3 += m * letterarr[j].v;
		m *= 10;
	}
	//cout << val1 << " * " << val2 << " = " << val3 << endl;
	if (val3 == (val1 * val2))
		return 1;
	else
		return 0;
}*/