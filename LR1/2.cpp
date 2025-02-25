#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    string id;
    cout << "Введите идентификатор \n";
    cin >> id;
    int x;
    x = id.length();

    cout << "Ваш пароль: \n";

    //12
    string b12 = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (int i = 1; i <= 2; i++) {
        cout << b12[rand() % 33];
    }// 2 буквы большие 
    //12

    
    //3
    int N = (rand() % 100) / 10;
    //3


    //4
    cout << rand() % 10;//от 0 до 9 (b4)
    //4
    

    //5
    vector<char> specialCharacters = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*' };
    cout << specialCharacters[rand() % specialCharacters.size()]; //b5
    //5
    

    //6
    string b6 = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    cout << b6[rand() % 33];
    //6
}
