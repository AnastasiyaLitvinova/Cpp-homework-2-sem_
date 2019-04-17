#include <iostream>
#include "ComplexNumber.h";

using namespace std;
const int N = 20; 

void InizializeComplexVector(vector<ComplexNumber>&, vector<ComplexNumber>&, char* filename, int dimension = 20); 
void WorkToVector(vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&);
void Show(vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&, vector<ComplexNumber>&);
void swap(ComplexNumber& a, ComplexNumber& b);
int main()
{
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	char File[N] = "WorkFile1.txt"; 
	int n;   
	cout << "Ââåäèòå ðàçìåðíîñòü âåêòîðà èç êîìïëåêñíûõ êîîðäèíàò: "; 
	cin >> n;
	ComplexNumber* cn = new ComplexNumber[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> cn[i];
	}

	system("cls");

	for (int i = 0; i < n; ++i) {
		std::cout << cn[i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (cn[j].GetImaginar() < cn[j + 1].GetImaginar())
				swap(cn[j], cn[j + 1]);
		}
	}

	for (int i = 0; i < n; ++i) {
		std::cout << cn[i] << " ";
	}


	delete[] cn;

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}


void swap(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber t = a;
	a = b;
	b = t;
}

void InizializeComplexVector(vector<ComplexNumber>& myVect1, vector<ComplexNumber>& myVect2, char* filename, int dimension)
{
	ifstream streamIn(filename);

	if (!streamIn.is_open())
	{
		cout << "Íåëüçÿ îòêðûòü ôàéë äëÿ ÷òåíèÿ!" << endl;
		system("pause");
		exit(1);
	}
	double real, imaginar; 
	for (int i = 0; i < dimension; i++)
	{
		streamIn >> real >> imaginar; 
		myVect1.push_back(ComplexNumber(real, imaginar)); 
		streamIn >> real >> imaginar; 
		myVect2.push_back(ComplexNumber(real, imaginar)); 
	}
}

void WorkToVector(vector<ComplexNumber>& myVect1, vector<ComplexNumber>& myVect2, vector<ComplexNumber>& myVectsum, vector<ComplexNumber>& myVectdif, vector<ComplexNumber>& myVectfact, vector<ComplexNumber>& myVectdiv)
{
	for (int i = 0; i < myVect1.size(); i++)
	{
		myVectsum.push_back(myVect1[i] + myVect2[i]); 
		myVectdif.push_back(myVect1[i] - myVect2[i]);
		myVectfact.push_back(myVect1[i] * myVect2[i]);
		myVectdiv.push_back(myVect1[i] / myVect2[i]);
	}
}

void Show(vector<ComplexNumber>& myVect1, vector<ComplexNumber>& myVect2, vector<ComplexNumber>& myVectsum, vector<ComplexNumber>& myVectdif, vector<ComplexNumber>& myVectfact, vector<ComplexNumber>& myVectdiv)
{
	for (int i = 0; i < myVect1.size(); i++)
	{
		cout << "| " << myVect1[i] << " |  +\t\t\t" << "| " << myVect2[i] << " |= \t\t\t | " << myVectsum[i] << " |\n\n";
		cout << "| " << myVect1[i] << " |  -\t\t\t" << "| " << myVect2[i] << " |= \t\t\t | " << myVectdif[i] << " |\n\n";
		cout << "| " << myVect1[i] << " |  *\t\t\t" << "| " << myVect2[i] << " |= \t\t\t | " << myVectfact[i] <<" |\n\n";
		cout << "| " << myVect1[i] << " |  :\t\t\t" << "| " << myVect2[i] << " |= \t\t\t | " << myVectdiv[i] << " |\n\n";
	}
}
