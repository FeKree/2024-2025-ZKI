#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>

bool hasUniqueDigits(int number) {
    std::set<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (digits.find(digit) != digits.end()) {
            return false;
        }
        digits.insert(digit);
        number /= 10;
    }
    return true; 
}

int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    int number;
    do {
        number = gen() % 9000 + 1000; 
    } while (!hasUniqueDigits(number));
    return number;
}

std::pair<int, int> getBullsAndCows(int secret, int guess) {
    int bulls = 0;
    int cows = 0;
    std::vector<int> secretDigits(4), guessDigits(4);

    for (int i = 3; i >= 0; --i) {
        secretDigits[i] = secret % 10;
        guessDigits[i] = guess % 10;
        secret /= 10;
        guess /= 10;
    }

    for (int i = 0; i < 4; ++i) {
        if (guessDigits[i] == secretDigits[i]) {
            bulls++;
        }
        else if (std::find(secretDigits.begin(), secretDigits.end(), guessDigits[i]) != secretDigits.end()) {
            cows++;
        }
    }

    return { bulls, cows };
}

int main() {
    setlocale(LC_ALL, "ru");
    int secretNumber = generateRandomNumber();
    int guess;
    int attempts = 0;

    std::cout << "Добро пожаловать в игру «Быки и коровы»!" << std::endl;
    std::cout << "Угадайте четырехзначное число с разными цифрами." << std::endl;

    while (true) {
        std::cout << "Введите вашу догадку (четырехзначное число): ";
        std::cin >> guess;

        if (guess < 1000 || guess > 9999 || !hasUniqueDigits(guess)) {
            std::cout << "Ошибка: введите корректное четырехзначное число с уникальными цифрами." << std::endl;
            continue;
        }

        attempts++;
        std::pair<int, int> result = getBullsAndCows(secretNumber, guess);
        int bulls = result.first;
        int cows = result.second;

        std::cout << "Быки: " << bulls << ", Коровы: " << cows << std::endl;

        if (bulls == 4) {
            std::cout << "Поздравляем! Вы угадали число " << secretNumber << " за " << attempts << " попыток!" << std::endl;
            break;
        }
    }

    return 0;
}
