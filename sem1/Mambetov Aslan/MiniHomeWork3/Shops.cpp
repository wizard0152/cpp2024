#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class ItemBase {
public:
    std::string name;
    int price;
    int weight;


    void parse(std::string s) {

    }
};

class ItemFood : public ItemBase {
public:
    int calories;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        this->price = stoi(vars[1]);
        this->weight = stoi(vars[3]);
        this->calories = stoi(vars[2]);
        this->name = vars[0];
    }
};
class ItemTech : public ItemBase {
public:
    int energyExpend;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        this->price = stoi(vars[1]);
        this->weight = stoi(vars[3]);
        this->energyExpend = stoi(vars[2]);
        this->name = vars[0];
    }
};
class ItemCar : public ItemBase {
public:
    int speed;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        this->price = stoi(vars[1]);
        this->weight = stoi(vars[3]);
        this->speed = stoi(vars[2]);
        this->name = vars[0];
    }
};

class Shop {
public:
    std::vector<ItemBase> items;

    int getAveragePrice() {
        int result = 0;
        if (items.empty())
            return 0;
        for (auto item : items)
            result += item.price;
        return result / items.size();
    }
    int getAverageWeight() {
        int result = 0;
        if (items.empty())
            return 0;
        for (auto item : items)
            result += item.weight;
        return result / items.size();
    }
};



int main() {
    setlocale(LC_ALL, "ru");
    Shop techShop, carShop, foodShop;
    std::ifstream in;
    in.open("data.txt");
    std::string line;
    getline(in, line);
    getline(in, line);
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        ItemTech item;
        item.parse(line);
        techShop.items.push_back(item);
    }
    getline(in, line);
    getline(in, line);
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        ItemFood item;
        item.parse(line);
        foodShop.items.push_back(item);
    }
    getline(in, line);
    getline(in, line);
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        ItemCar item;
        item.parse(line);
        carShop.items.push_back(item);
    }
    

    std::cout << "Средняя цена в первом магазине: " << techShop.getAveragePrice() << '\n';
    std::cout << "Средний вес в первом магазине: " << techShop.getAverageWeight() << '\n';
    std::cout << "Средняя цена в втором магазине: " << foodShop.getAveragePrice() << '\n';
    std::cout << "Средний вес в втором магазине: " << foodShop.getAverageWeight() << '\n';
    std::cout << "Средняя цена в третьем магазине: " << carShop.getAveragePrice() << '\n';
    std::cout << "Средний вес в третьем магазине: " << carShop.getAverageWeight() << '\n';

}