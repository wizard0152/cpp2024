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

    std::cout << "����, �������� �� �������� ������� �� ��������. ��������� ��������� �� ����������� ������ �� 100000, �������� ������������� ���� ��������� ����� � ����������� ����.\n\n���� �� ������, ������� ��� ������\n";
    std::cin >> something;

    for (int i = 1; i <= 100000; i++)
    {
        int s = Syracuse(i);
        if (s == 1)
            std::cout << "����� " << i << " �������: " << Syracuse(i) << "   |   �����! ���������\n";
        else
        {
            std::cout << "����� " << i << " �������: " << Syracuse(i) << "��������!!! �� ������ ������������ �! (������ ������� �� �� ����� :)";
            return 0;
        }
    }
    return 0;
}