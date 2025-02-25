#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() 
{

	setlocale(0, "");
	srand(time(NULL));
	double P(pow(10, -5)), V(20.0), T(1);
	int S;
	S = round((V * T) / P);
	cout << "Пароль: " << endl;
	string A = "abcdefghijklmnopqrstuvwxyzАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЭЮЯ";
	int L = 6;

	for (int k = 1; k <= L; k++) {
		cout << A[rand() % 54];
	}

	cout << endl << "S:" << S;
}
