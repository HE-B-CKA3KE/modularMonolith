#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "func.h"
using namespace std;

int kilk(string a);
void split(string* words, string a);
void max_word(string* s, int k, int& max, int& max_position, string& maxword);
void min_word(string* s, int k, int& min, int& min_position, string& minword);
int main()
{
	SetConsoleOutputCP(1251);
	cout << "Введіть рядок: ";
	string a;
	getline(cin, a);
	int k = kilk(a);
	string* words = new string[k];
	split(words, a);

	for (int i = 0; i < k; i++)
	{
		cout <<i+1<<" - "<< words[i] << endl;
	}
	int max = 0;int max_position = 0;string maxword;
	max_word(words, k,max,max_position,maxword);
	cout << "maximal string - "<< max<<", it`s position - "<< max_position+1<<"("<<maxword<<")" << endl;
	int min = 100000;int min_position=0;string minword;
	void min_word(string * s, int k, int& min, int& min_position, string & minword);
	cout << "minimal string - " << min << ", it`s position - " << min_position + 1 << "(" << minword << ")" << endl;
	delete[] words;
}

int kilk(string a)
{
	int n = 1;
	string delimiter = " ";
	int pos = 0;
	while ((pos = a.find(delimiter, pos + 1)) != string::npos) {
		n++;
	}
	return n;
}

void split(string* words, string a)
{
	string delimiter = " ";
	int pos = 0;
	int n = 0;
	while ((pos = a.find(delimiter)) != string::npos)
	{		//цикл, для розбиття рядка на підрядки
		words[n] = a.substr(0, pos);
		a.erase(0, pos + delimiter.length());
		n++;												//кількість слів
	}
	words[n] = a;
}
void max_word(string* s,int k,int &max,int &max_position,string &maxword)
{
	for (int i = 0; i < k; i++)
	{
		if (s[i].length() > max)
		{
			max = s[i].length();
			max_position = i;
			maxword = s[i];
		}
	}
}

void min_word(string* s, int k, int& min, int& min_position, string& minword)
{
	for (int i = 0; i < k; i++)
	{
		if (s[i].length() < min)
		{
			min = s[i].length();
			min_position = i;
			minword = s[i];
		}
	}
}