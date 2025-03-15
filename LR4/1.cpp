#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <set>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    random_device rd;
    mt19937 gen(rd());

    // 1.
    uniform_int_distribution<> dist1(3, 12);
    cout << "Случайные целые числа от 3 до 12:\n";
    for (int i = 0; i < 10; ++i) {
        cout << dist1(gen) << " ";
    }
    cout << "\n\n";

    // 2.
    set<int> set2 = { -3, 0, 6, 9, 12, 15 };
    vector<int> vec2(set2.begin(), set2.end());
    cout << "Случайные числа из множества {-3, 0, 6, 9, 12, 15}:\n";
    for (int i = 0; i < 10; ++i) {
        cout << vec2[dist1(gen) % vec2.size()] << " ";
    }
    cout << "\n\n";

    // 3.
    uniform_real_distribution<> dist3(3.0, 12.0);
    cout << "Случайные вещественные числа от 3 до 12:\n";
    for (int i = 0; i < 10; ++i) {
        cout << fixed << setprecision(2) << dist3(gen) << " ";
    }
    cout << "\n\n";

    // 4.
    cout << "Случайные числа от -2.3 до 10.7 с шагом 0.1:\n";
    uniform_int_distribution<> dist4(-23, 107);
    for (int i = 0; i < 10; ++i) {
        std::cout << std::fixed << std::setprecision(1) << dist4(gen) / 10.0 << " ";
    }
    cout << "\n\n";

    // 5.
    set<int> set5 = { -30, 10, 63, 59, 120, 175 };
    vector<int> vec5(set5.begin(), set5.end());
    cout << "Случайные числа из множества {-30, 10, 63, 59, 120, 175}:\n";
    for (int i = 0; i < 10; ++i) {
        cout << vec5[dist1(gen) % vec5.size()] << " ";
    }
    cout << "\n\n";

    // 6.
    vector<float> vec6;
    for (int i = 0; i <= 15; ++i) {
        vec6.push_back(pow(10, -i));
    }
    cout << "Случайные числа из множества {1, 0.1, 0.01, ..., 10^-15}:\n";
    for (int i = 0; i < 10; ++i) {
        cout << vec6[dist1(gen) % vec6.size()] << " ";
    }
    cout << "\n";

    return 0;
}
