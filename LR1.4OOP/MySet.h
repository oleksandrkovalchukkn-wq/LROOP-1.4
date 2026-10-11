#pragma once
#include <string>

class MySet {
private:
    // Максимально можлива кількість елементів (універсум від 0 до 99)
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];

public:
    // Методи доступу (гетери та сетери з перевіркою меж)
    int getElement(int index) const;
    bool setElement(int index, int value);

    // Обов'язкові методи
    void Init();
    void Read();
    void Display() const;
    std::string toString() const;

    // Специфічні операції варіанта 18
    bool add(int element);
    bool remove(int element);
    MySet intersectWith(const MySet& other) const;
    MySet unionWith(const MySet& other) const;
    MySet differenceWith(const MySet& other) const;
};