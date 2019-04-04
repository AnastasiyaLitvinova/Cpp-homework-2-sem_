// дана англо яз строка , нужно в этом тексте зашифровать все слова заданной длины
// по правилу буква соответсвует какому-нибудь числу в круглых скобках , знаки препиная не кодировать
// чтобы можно будет потом изменить правила шифрования
#include <iostream>
using namespace std;

int length(char* arr);
char* getArray();
int getLength(int length);
bool symbolCheck(char a);
bool isTrueLen(char* string, int index, int length, int size);
void solve(char*& string, int leng, int size);

int main()
{
	int n;
	cout << "Enter size word n:" << endl;
	cin >> n;

	char* string = getArray();
	cout<< string<< endl;
	solve(string, n, length(string));
	cout<< endl;
	delete[] string;
	system("pause");
	return 0;

}

int length(char* arr)
{
	int index = 0;
	while (arr[index])
	{
		index++;
	}
	return index;
}

char* getArray()
{
	cout << "Enter array:" << endl;
	char* len = new char[256];
	cin.getline(len, 256);

	char* string = new char[length(len)];
	for (int i = 0; i < length(string); ++i)
	{
		string[i] = len[i];
	}

	delete[] len;
	return string;

}

int getLength(int length)
{
	cout << "Enter name: " << endl;
	int n;
	while (true)
	{
		cin >> n;
		if (n < length && n > 0)
		{
			return n;
		}

		cout << "Invalid data, repeat" << endl;
	}
}

bool symbolCheck(char a) 
{
	if (a >= 65 && a <= 90 || a >= 97 && a <= 122)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isTrueLen(char* string, int index, int length, int size) 
{
	if (size - index < length)
		return false;
	int len = 1;
	while (symbolCheck(string[index + len]))
	{
		++len;
	}
	if (len == length)
	{
		return true;
	}
	return false;
}

void solve(char*& string, int leng, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		if (symbolCheck(string[i]))
		{
			if (isTrueLen(string, i, leng, size))
			{
				int newSize = length(string) + leng * 2;

				char* substring = new char[newSize];
				for (int j = 0; j < newSize; ++j)
				{
					if (j < i)
					{
						substring[j] = string[j];
					}
					if (j == i) 
					{
						for (int q = 0; q < leng * 3; ++q)
						{
							if (q % 3 == 0 || q == 0)
							{
								substring[q] = '(';
							}
							if (q % 3 == 1) {
								substring[i] = 5;
							}
						}
					}
				}
			}
		}
	}
}



