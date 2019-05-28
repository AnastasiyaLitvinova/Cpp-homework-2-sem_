#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

typedef char*(*Key)(int);
typedef char*(*Rule)(char*, Key, int);

const int N = 256;

void CreateFile(const char*, char*);
int ValidationOfElement(int);
char* ValidationOfArray(char*, int);
char* AllocateMemoryChar(int);
void ToEncode(char*, Rule, int, Key);
char* GetRule(char*, Key, int);
char RegisterIndependent(char);
void ToReplaceWord(char*, char*, char*, int);
char* ConvertToChar(int);
void AddFile(const char*, char*);

using namespace std;

int main()
{
	const char* fileName = "C:\\Users\\Nastya\\repos\\ïðîåêòû\\2 ñåìåñòð\\28.05.2019\\Project28\\test.txt";
	char* string = AllocateMemoryChar(N);

	cout << "Please enter string" << endl;
	cin.getline(string, N);

	CreateFile(fileName, string);

	int n;
	cout << "Please enter of what length word you want to encode:" << endl;
	cin >> n;
	try
	{
		n = ValidationOfElement(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	ToEncode(string, GetRule, n, ConvertToChar);
	AddFile(fileName, string);

	system("pause");
	return 0;
}

void CreateFile(const char* fileName, char* string)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	streamOut << "Source string:" << endl;
	streamOut << string;
	streamOut << endl;

	streamOut.close();
}

int ValidationOfElement(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("The count of elements of array can't be less or equal to 0");
	}
	else
	{
		return n;
	}
}

char* ValidationOfArray(char* array, int n)
{
	try
	{
		n = ValidationOfElement(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	if (array == nullptr)
	{
		throw invalid_argument("The pointer to array can't be equal to nullptr");
	}

	return array;
}

char* AllocateMemoryChar(int n)
{
	char* array = new char[n];

	try
	{
		array = ValidationOfArray(array, n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return array;
}

void ToEncode(char* string, Rule rule, int n, Key key)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pword = strpbrk(string, symbols);

	while (pword)
	{
		int length = strspn(pword, symbols);

		if (length == n)
		{
			ToReplaceWord(string, pword, rule(pword, key, n), n);
		}

		pword += length;
		pword = strpbrk(pword, symbols);

	}

}

char* GetRule(char* word, Key key, int n)
{
	const char* symbols = "zyxvwutsrqpomnlkjihgfedcba";
	char* encodingWord = new char[n * 4];

	int k = 0;

	for (int j = 0; j < n; j++)
	{
		word[j] = RegisterIndependent(word[j]);

		for (int i = 0; i < strlen(symbols); i++)
		{
			if (word[j] == symbols[i])
			{
				strcpy(encodingWord + k, key(i + 1));
				k += 4;
			}
		}
	}

	return encodingWord;
}

char RegisterIndependent(char symbol)
{
	return (symbol < 'a') ? symbol + 32 : symbol;
}

void ToReplaceWord(char* string, char* replacingWord, char* word, int length)
{
	char* copyString = AllocateMemoryChar(N);

	strcpy(copyString, replacingWord + length);
	strcpy(replacingWord, word);
	strcpy(strstr(string, word) + length * 4, copyString);
}

char* ConvertToChar(int number)
{
	char* code = new char[5];
	int i = 3;


	code[i] = ']';
	if (number < 10)
	{
		i--;
		code[i] = number % 10 + '0';
		code[i - 1] = '0';

	}
	else
	{
		while (number)
		{
			i--;
			code[i] = number % 10 + '0';
			number /= 10;

		}

	}

	code[0] = '[';
	return code;
}

void AddFile(const char* fileName, char* string)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\nEncoded string!\n";
	streamOut << string;
	streamOut << endl;

	streamOut.close();
}