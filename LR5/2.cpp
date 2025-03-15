#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Функция для создания квадрата Полибия
void createPolybiusSquare(unordered_map<char, string>& square) {
    char letters[5][5] = {
        {'B', 'O', 'Y', 'A', 'R'},
        {'C', 'D', 'E', 'F', 'G'},
        {'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'P', 'Q', 'S'},
        {'T', 'U', 'V', 'W', 'Z'}
    };

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            square[letters[i][j]] = to_string(i + 1) + to_string(j + 1);
        }
    }
}

// Функция для шифрования фразы
void encrypt(const string& phrase, unordered_map<char, string>& square) {
    string direct, withSeparator, reverse;

    // Прямое шифрование
    for (char c : phrase) {
        // Приводим к верхнему регистру, чтобы избежать проблем с регистром
        c = toupper(c);
        if (square.find(c) != square.end()) {
            direct += square[c] + " ";
            withSeparator += square[c] + "X ";
            reverse.insert(0, square[c] + " ");
        }
    }

    // Убираем последний пробел
    if (!direct.empty()) direct.pop_back();
    if (!withSeparator.empty()) withSeparator.pop_back();
    if (!reverse.empty()) reverse.pop_back();

    // Вывод результатов
    cout << "Прямое шифрование: " << direct << endl;
    cout << "Шифрование с разделителями: " << withSeparator << endl;
    cout << "Шифрование в обратном порядке: " << reverse << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    unordered_map<char, string> polybiusSquare;
    createPolybiusSquare(polybiusSquare);

    string phrase = "BOYAR";
    encrypt(phrase, polybiusSquare);

    return 0;
}
