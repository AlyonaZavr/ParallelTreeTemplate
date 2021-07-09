#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> numberarr, string first, string second, string result, vector<char> abc)//функция проверки значений
{
	int val1 = 0, val2 = 0, val3 = 0, m = 1;//val являются полноценными числами, соответствующие словам
	for (int i = first.size() - 1; i >= 0; i--)// выбираем букву из первого слова
	{
		for (int j = 0; j < abc.size();j++)//выбираем букву из алфавита
		{
			if (first[i] == abc[j])//если они совпали,
			{
				val1 += m * numberarr[j];// то добавляем к чису (благодаря m создаются единицы, десятки и т.д.)
				break;
			}
		}
		m *= 10;//идем к следующей по старшенству цифре числа
	}
	m = 1;
	for (int i = second.size() - 1; i >= 0; i--)//составляем число, аналогично первому
	{
		for (int j = 0; j < abc.size(); j++)
		{
			if (second[i] == abc[j])
			{
				val2 += m * numberarr[j];
				break;
			}
		}
		m *= 10;
	}
	m = 1;
	for (int i = result.size() - 1; i >= 0; i--)//составляем число, аналогично первому
	{
		for (int j = 0; j < abc.size(); j++)
		{
			if (result[i] == abc[j])
			{
				val3 += m * numberarr[j];
				break;
			}
		}
		m *= 10;
	}
	if (val3 == val1 * val2)//проверяем на справедливость
		return 1;
	return 0;
}

void podbor(vector<string>&resultetion,int index, vector<int> numberarr, string first, string second, string result, vector<char> abc)//функция подбора значений. строки входят в эту функцию из-за невозможности вынести проверку из нее
{
	//vector<string> resultetion;
	string str ;
	string tempstr;
		for (int i = 0; i < 10; i++)//выбираем цифру
		{
			bool k = 1;//проверяем, что она еще не была выбрана раньше
			for (int j = 0; j < index; j++)
			{
				if (i == numberarr[j])
					k = 0;
			}
			if (k)//если все хорошо, присваиваем значение и заново вызываем функцию, иначе ищем другую цифру
			{
				numberarr[index] = i;
				if (index == numberarr.size()-1)//смотрим, чтобы значения не выходили за предел имеющихся
				{
					//иначе делаем проверку на соответствие выбранных значений действительности
					if (check(numberarr, first, second, result, abc))
					{
						for (int j = 0; j < numberarr.size(); j++)
						{
							//cout << abc[j];
							//cout <<abc[j]<<"; ";
							tempstr = abc[j];
							str += tempstr + " = " + to_string(numberarr[j]) + "; ";
							

							//cout<<str<< "*"<<resultetion[0]<<"*";
						}
						resultetion.push_back(str);
						//cout << endl;
					}
				}
				else//если еще есть незаполненные значения, вызываем заново
				{
					podbor(resultetion,index + 1, numberarr, first, second, result, abc);
				}
			}
		}
		//return resultetion;
}

bool ABC(vector<string>& resultetion,string first, string second, string result)//составляет алфавит множества(на выходе строка) дабы сопоставить его с цифрами методом подборы
{
	vector<char> abcd;//будущий алфавит
	int i = 0;
	string abc = first + second + result;
	while (i < abc.size() - 1)//находим алфавит-строку
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

	if (abc.size() > 10)//проверяем, что колличество букв в алфавите не превышает колличество цифр (0-9)
		return 0;

	cout <<"алфавит данного ребуса: "<<abc << endl;

	for (int i = 0; i < abc.size(); i++)//переписываем алфавит-строку в алфавит-вектор 
		abcd.push_back(abc[i]);

	vector<int> v(abcd.size(), -1);//будущий алфавит цифр
	podbor(resultetion,0, v, first, second, result, abcd);//подбираем ответ

	return 1;
}