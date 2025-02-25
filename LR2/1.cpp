#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(const string& input, int m) {
    string text = input;
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    int n = (text.length() + m - 1) / m;
    vector<vector<char>> table(m, vector<char>(n, ' '));
    for (int i = 0; i < text.length(); ++i) {
        table[i % m][i / m] = text[i];
    }
    string encrypted;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (table[i][j] != ' ') {
                encrypted += table[i][j];
            }
        }
    }
    cout << "Таблица шифрования:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Зашифрованное сообщение: ";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j];
        }
    }
    return encrypted;
}

int main() {
    setlocale(LC_ALL, "ru");
    string message = "Купи биткоин не забудь";
    int m = 5;

    string encryptedMessage = encrypt(message, m);

    return 0;
}
