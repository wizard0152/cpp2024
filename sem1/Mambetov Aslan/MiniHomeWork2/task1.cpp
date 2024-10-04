#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>


std::string convertNumber(long long num, int system) {
    char digits[36]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', };
    std::vector<int> rests;
    std::string result;

    while (num > 0) 
    {
        rests.push_back(num % system);
        num /= system;
    }

    reverse(rests.begin(), rests.end());

    for (auto rest : rests) 
    {
        result += digits[rest];
    }
    return result;
}   


int main() {
    setlocale(LC_ALL, "Russian");

    long long n;
    long long sys;

    std::cout << "Введите ваше число: ";
    std::cin >> n;
    std::cout << "\nВведите систему счисления в которую хотите перевести: ";
    std::cin >> sys;
    std::cout << "\nРезультат: " << convertNumber(n, sys) << "\n";
    return 0;
}