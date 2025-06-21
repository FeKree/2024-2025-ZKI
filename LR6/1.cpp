#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long modpow(long long base, long long exp, long long modulus) {
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

string encryptRSA(string text, long long e, long long n) {
    string encryptedText = "";
    for (char c : text) {
        long long m = c;
        long long encryptedChar = modpow(m, e, n);
        encryptedText += to_string(encryptedChar) + " ";
    }
    return encryptedText;
}

string decryptRSA(string encryptedText, long long d, long long n) {
    string decryptedText = "";
    size_t pos = 0;
    while ((pos = encryptedText.find(" ")) != string::npos) {
        long long encryptedChar = stoll(encryptedText.substr(0, pos));
        long long decryptedChar = modpow(encryptedChar, d, n);
        decryptedText += char(decryptedChar);
        encryptedText.erase(0, pos + 1);
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "ru");
    long long p = 61;
    long long q = 53;

    long long n = p * q;
    long long m = (p - 1) * (q - 1);

    long long e = 17;
    long long d = 2753;
    string text;
    cout << "Введите текст для шифрования: ";
    getline(cin, text);

    string encryptedText = encryptRSA(text, e, n);
    cout << "Зашифрованный текст: " << encryptedText << endl;

    string decryptedText = decryptRSA(encryptedText, d, n);
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
