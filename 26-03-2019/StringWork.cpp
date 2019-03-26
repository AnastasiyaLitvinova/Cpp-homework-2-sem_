#include <iostream>
#include "StringLibrary.h"

using namespace std;
using namespace StringExtention;

typedef bool(*Key)(char*, char*);
void quickSort(char**, int, int, Key);

bool CompareByAlphabet(char*, char*);

int main()
{
	char string[] = "Happy birthday to me!!!";
	int n = strlen(string);
	cout << n;
	char** words = GetWords(string, n);
	displayWords(words, n);
	quickSort(words, 0, n - 1, CompareByAlphabet);
	displayWords(words, n);

	system("pause");
	return 0;
}

void quickSort(char** words, int left, int right, Key key)
{
	int i = left, j = right;
	char* pivot = words[(left + right) / 2];
	while (i <= j)
	{
		while ( ! key(words[i], pivot))
		{
			i++;
		}
		while ( ! key(words[j], pivot))
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(words[i], words[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSort(words, left, j, key);
	}
	if (right > i)
	{
		quickSort(words, j, right, key);
	}
}


bool CompareByAlphabet(char* letter0, char* letter1)
{
	return (int) *letter0 > (int) *letter1;
}