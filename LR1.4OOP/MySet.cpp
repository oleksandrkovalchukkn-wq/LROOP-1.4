#include "MySet.h"
#include <iostream>
#include <sstream>

using namespace std;

// Безпечне отримання значення (є елемент чи ні)
int MySet::getElement(int index) const {
    if (index >= 0 && index < MAX_SIZE) {
        return data[index];
    }
    return 0;
}

// Захищений запис: допускає лише індекси 0-99 та значення 0 або 1
bool MySet::setElement(int index, int value) {
    if (index >= 0 && index < MAX_SIZE && (value == 0 || value == 1)) {
        data[index] = value;
        return true;
    }
    return false;
}

void MySet::Init() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        data[i] = 0;
    }
}

void MySet::Read() {
    Init();
    int count, elem;
    cout << "Скільки елементів додати у множину? ";
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cout << "Елемент " << i + 1 << " (від 0 до " << MAX_SIZE - 1 << "): ";
        cin >> elem;
        add(elem);
    }
}

string MySet::toString() const {
    stringstream ss;
    ss << "{ ";
    bool first = true;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (data[i] == 1) { // Якщо елемент присутній у масиві
            if (!first) ss << ", ";
            ss << i;
            first = false;
        }
    }
    ss << " }";
    return ss.str();
}

void MySet::Display() const {
    cout << toString() << endl;
}

// Додавання елемента = запис 1 у комірку
bool MySet::add(int element) {
    return setElement(element, 1);
}

// Вилучення елемента = запис 0 у комірку
bool MySet::remove(int element) {
    return setElement(element, 0);
}

// Перетин (спільні елементи для обох множин)
MySet MySet::intersectWith(const MySet& other) const {
    MySet result;
    result.Init();
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (this->data[i] == 1 && other.data[i] == 1) {
            result.data[i] = 1;
        }
    }
    return result;
}

// Об'єднання (усі елементи з обох множин без дублікатів)
MySet MySet::unionWith(const MySet& other) const {
    MySet result;
    result.Init();
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (this->data[i] == 1 || other.data[i] == 1) {
            result.data[i] = 1;
        }
    }
    return result;
}

// Різниця (елементи, які є в першій множині, але відсутні в другій)
MySet MySet::differenceWith(const MySet& other) const {
    MySet result;
    result.Init();
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (this->data[i] == 1 && other.data[i] == 0) {
            result.data[i] = 1;
        }
    }
    return result;
}