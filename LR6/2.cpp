#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isPrime(long long number) {
    if (number <= 1) return false;
    for (long long i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

long long generatePrimeNumber() {
    srand((unsigned int)time(0));
    long long primeNumber;
    do {
        primeNumber = (rand() % 1000) + 100;
    } while (!isPrime(primeNumber));
    return primeNumber;
}

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

string encryptElGamal(string text, long long p, long long g, long long y, long long k) {
    string encryptedText = "";
    for (char c : text) {
        long long m = c;
        long long c1 = modpow(g, k, p);
        long long c2 = (m * modpow(y, k, p)) % p;
        encryptedText += to_string(c1) + " " + to_string(c2) + " ";
    }
    return encryptedText;
}
string decryptElGamal(string encryptedText, long long p, long long x) {
    string decryptedText = "";
    size_t pos = 0;
    while ((pos = encryptedText.find(" ")) != string::npos) {
        long long c1 = stoll(encryptedText.substr(0, pos));
        encryptedText.erase(0, pos + 1);
        pos = encryptedText.find(" ");
        long long c2 = stoll(encryptedText.substr(0, pos));
        encryptedText.erase(0, pos + 1);
        long long m = (c2 * modpow(modpow(c1, x, p), p - 2, p)) % p;
        decryptedText += char(m);
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "ru");
    long long p = generatePrimeNumber();
    long long g = 2;
    long long x = 10;
    long long y = modpow(g, x, p);

    string text;
    cout << "Введите текст для шифрования: ";
    getline(cin, text);
    long long k = 5;
    string encryptedText = encryptElGamal(text, p, g, y, k);
    cout << "Зашифрованный текст: " << encryptedText << endl;
    string decryptedText = decryptElGamal(encryptedText, p, x);
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
