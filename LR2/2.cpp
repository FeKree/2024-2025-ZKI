#include<iostream>  
#include<string.h> 
#include<string> 
#include<vector>

using namespace std;


class MagicSquareCipher {
private:
    vector<vector<int>> square;
    int size;

    void generateMagicSquare(const vector<int>& numbers) {
        size = static_cast<int>(sqrt(numbers.size()));
        square.resize(size, vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                square[i][j] = numbers[i * size + j];
            }
        }
    }

public:
    MagicSquareCipher(const vector<int>& numbers) {
        generateMagicSquare(numbers);
    }

    string encrypt(const string& text) {
        string adjustedText = text;
        int totalCells = size * size;
        while (adjustedText.size() < totalCells) {
            adjustedText += '.';
        }

        string encryptedText(totalCells, ' ');
        for (int i = 0; i < totalCells; ++i) {
            int index = square[i / size][i % size] - 1;
            if (index < adjustedText.size()) {
                encryptedText[i] = adjustedText[index];
            }
        }
        return encryptedText;
    }
};

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RU");

    const int SIZE_5x5 = 5, SIZE_6x6 = 6;

    vector<int> magicSquare5x5 = {
        21, 24, 2, 3, 15,
        1, 6, 16, 22, 20,
        14, 12, 19, 7, 13,
        25, 5, 17, 10, 8,
        4, 18, 11, 23, 9
    };

    vector<int> magicSquare6x6 = {
        22, 36, 7, 2, 9, 35,
        26, 18, 31, 10, 5, 21,
        13, 23, 15, 24, 28, 8,
        12, 4, 14, 34, 30, 17,
        6, 1, 33, 25, 19, 27,
        32, 29, 11, 16, 20, 3
    };

    MagicSquareCipher Square5x5(magicSquare5x5);
    MagicSquareCipher Square6x6(magicSquare6x6);

    const string ZADANIE_1 = "Это сообщение мне в прошлом";
    const string ZADANIE_2_1 = "Это сообщение для меня в будущем";
    const string ZADANIE_2_2 = "Это второе сообщение для меня в будущем";


    cout << "Сейчас шифруется следующий текст: \"" << ZADANIE_2_1 << "\" методом магического квадрата (5x5)" << endl << endl;
    cout << "Результат шифрования: \"" << Square5x5.encrypt(ZADANIE_2_1) << "\"" << endl << endl;

    cout << "Сейчас шифруется следующий текст: \"" << ZADANIE_2_2 << "\" методом магического квадрата (6x6)" << endl << endl;
    cout << "Результат шифрования: \"" << Square6x6.encrypt(ZADANIE_2_2) << "\"" << endl << endl;

    cout << "Программа завершила свое выполнение.";
}
