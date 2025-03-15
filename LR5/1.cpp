#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string permute(const string& text, const vector<int>& order) {
    string permuted(text.size(), ' ');
    for (size_t i = 0; i < order.size(); i++) {
        permuted[i] = text[order[i]];
    }
    return permuted;
}
string doubleTranspositionCipher(const string& input, const vector<int>& rowOrder, const vector<int>& colOrder) {
    // Определяем размер таблицы
    int rows = rowOrder.size();
    int cols = (input.size() + rows - 1) / rows; 
    vector<string> table(rows, string(cols, ' '));
    for (size_t i = 0; i < input.size(); i++) {
        table[i % rows][i / rows] = input[i];
    }
    string intermediate;
    for (const auto& row : rowOrder) {
        intermediate += table[row];
    }
    string encrypted;
    for (int col : colOrder) {
        for (int row = 0; row < rows; row++) {
            if (col < cols) {
                encrypted += intermediate[row * cols + col];
            }
        }
    }

    return encrypted;
}

int main() {
    setlocale(LC_ALL, "ru");
    string input = "Бояр любит лысых парней";
    cout << input << endl;
    vector<int> rowOrder = { 2, 0, 1 }; 
    vector<int> colOrder = { 1, 0, 2 }; 

    // Удаляем пробелы для шифрования
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    string encrypted = doubleTranspositionCipher(input, rowOrder, colOrder);

    cout << "Зашифрованный текст: " << encrypted << endl;

    return 0;
}
