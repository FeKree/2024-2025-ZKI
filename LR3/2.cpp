#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int SIZE = 5;

vector<vector<char>> generatePlayfairSquare(const string& key) {
    string alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string keyUpper;


    keyUpper.erase(unique(keyUpper.begin(), keyUpper.end()), keyUpper.end());

    for (char c : alphabet) {
        if (keyUpper.find(c) == string::npos) keyUpper += c;
    }

    vector<vector<char>> square(SIZE, vector<char>(SIZE));
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            square[i][j] = keyUpper[index++];
        }
    }
    return square;
}

void findPosition(const vector<vector<char>>& square, char letter, int& row, int& col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (square[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string playfairEncrypt(const string& text, const string& key) {
    vector<vector<char>> square = generatePlayfairSquare(key);
    string processedText, encryptedText;

    for (char c : text) {
        if (c != ' ') processedText += toupper(c);
    }

    for (size_t i = 0; i < processedText.length(); i += 2) {
        if (i + 1 >= processedText.length() || processedText[i] == processedText[i + 1]) {
            processedText.insert(i + 1, "X");
        }
    }

    for (size_t i = 0; i < processedText.length(); i += 2) {
        int row1, col1, row2, col2;
        findPosition(square, processedText[i], row1, col1);
        findPosition(square, processedText[i + 1], row2, col2);

        if (row1 == row2) {
            encryptedText += square[row1][(col1 + 1) % SIZE];
            encryptedText += square[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText += square[(row1 + 1) % SIZE][col1];
            encryptedText += square[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText += square[row1][col2];
            encryptedText += square[row2][col1];
        }
    }
    return encryptedText;
}

int main() {
    setlocale(LC_ALL, "ru");

    const string ZD2_TEXT = "Чиполино Джанни Родари";
    cout << "Сейчас шифруется \"" << ZD2_TEXT << "\"..." << endl;
    cout << "Результат шифрования: " << playfairEncrypt(ZD2_TEXT, "шерсть") << endl << endl;
    return 0;
}
