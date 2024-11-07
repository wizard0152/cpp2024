#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>


int Syracuse(long long num) {
    while (num > 1)
        num % 2 == 0 ? num /= 2 : num = (num * 3 + 1) / 2;
    return num;
}


int main() {
    setlocale(LC_ALL, "Russian");

    std::string something;

    std::cout << "Итак, проверим ка гипотизу Сиракуз на практике. Попробуем проверить на натуральных числах до 100000, гипотеза опровергнится если программа зайдёт в бесконечный цикл.\n\nЕсли вы готовы, введите что угодно\n";
    std::cin >> something;

    for (int i = 1; i <= 100000; i++)
    {
        int s = Syracuse(i);
        if (s == 1)
            std::cout << "число " << i << " вернуло: " << Syracuse(i) << "   |   супер! Сработало\n";
        else
        {
            std::cout << "число " << i << " вернуло: " << Syracuse(i) << "Открытие!!! Мы смогли опровергнуть её! (такого конечно же не будет :)";
            return 0;
        }
    }
    return 0;
}