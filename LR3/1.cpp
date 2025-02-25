#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";
    int al = 32;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'А' && text[i] <= 'Я') {
            result += char(int(text[i] + shift - 'А') % al + 'А');
        }
        else if (text[i] >= 'а' && text[i] <= 'я') {
            result += char(int(text[i] + shift - 'а') % al + 'а');
        }
        else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    string text = "Шатуха Алексей Кириллович";
    int shift = 21;
    cout << "Оригинальный: " << text << endl;
    cout << "Зашифрованный " << caesarCipher(text, shift) << endl;
    return 0;
}
