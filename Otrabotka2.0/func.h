#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> numberarr, string first, string second, string result, vector<char> abc)//������� �������� ��������
{
	int val1 = 0, val2 = 0, val3 = 0, m = 1;//val �������� ������������ �������, ��������������� ������
	for (int i = first.size() - 1; i >= 0; i--)// �������� ����� �� ������� �����
	{
		for (int j = 0; j < abc.size();j++)//�������� ����� �� ��������
		{
			if (first[i] == abc[j])//���� ��� �������,
			{
				val1 += m * numberarr[j];// �� ��������� � ���� (��������� m ��������� �������, ������� � �.�.)
				break;
			}
		}
		m *= 10;//���� � ��������� �� ����������� ����� �����
	}
	m = 1;
	for (int i = second.size() - 1; i >= 0; i--)//���������� �����, ���������� �������
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
	for (int i = result.size() - 1; i >= 0; i--)//���������� �����, ���������� �������
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
	if (val3 == val1 * val2)//��������� �� ��������������
		return 1;
	return 0;
}

void podbor(vector<string>&resultetion,int index, vector<int> numberarr, string first, string second, string result, vector<char> abc)//������� ������� ��������. ������ ������ � ��� ������� ��-�� ������������� ������� �������� �� ���
{
	//vector<string> resultetion;
	string str ;
	string tempstr;
		for (int i = 0; i < 10; i++)//�������� �����
		{
			bool k = 1;//���������, ��� ��� ��� �� ���� ������� ������
			for (int j = 0; j < index; j++)
			{
				if (i == numberarr[j])
					k = 0;
			}
			if (k)//���� ��� ������, ����������� �������� � ������ �������� �������, ����� ���� ������ �����
			{
				numberarr[index] = i;
				if (index == numberarr.size()-1)//�������, ����� �������� �� �������� �� ������ ���������
				{
					//����� ������ �������� �� ������������ ��������� �������� ����������������
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
				else//���� ��� ���� ������������� ��������, �������� ������
				{
					podbor(resultetion,index + 1, numberarr, first, second, result, abc);
				}
			}
		}
		//return resultetion;
}

bool ABC(vector<string>& resultetion,string first, string second, string result)//���������� ������� ���������(�� ������ ������) ���� ����������� ��� � ������� ������� �������
{
	vector<char> abcd;//������� �������
	int i = 0;
	string abc = first + second + result;
	while (i < abc.size() - 1)//������� �������-������
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

	if (abc.size() > 10)//���������, ��� ����������� ���� � �������� �� ��������� ����������� ���� (0-9)
		return 0;

	cout <<"������� ������� ������: "<<abc << endl;

	for (int i = 0; i < abc.size(); i++)//������������ �������-������ � �������-������ 
		abcd.push_back(abc[i]);

	vector<int> v(abcd.size(), -1);//������� ������� ����
	podbor(resultetion,0, v, first, second, result, abcd);//��������� �����

	return 1;
}