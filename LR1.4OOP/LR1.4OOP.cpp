// Лабораторна робота №1.4 (Варіант 18)
// Студент: Ковальчук Олександр, група КН-2529Б

#include <iostream>
#include <Windows.h>
#include "MySet.h"

using namespace std;

void printMenu() {
    cout << "\n=========================================\n";
    cout << "          МЕНЮ: РОБОТА З МНОЖИНОЮ        \n";
    cout << "=========================================\n";
    cout << "1. Показати поточну множину А\n";
    cout << "2. Зібрати нову множину А\n";
    cout << "3. Додати один елемент до А\n";
    cout << "4. Вилучити один елемент з А\n";
    cout << "5. Знайти ПЕРЕТИН (Спільне між А та В)\n";
    cout << "6. Знайти ОБ'ЄДНАННЯ (Сума А та В)\n";
    cout << "7. Знайти РІЗНИЦЮ (А мінус В)\n";
    cout << "0. Вихід\n";
    cout << "=========================================\n";
    cout << "Оберіть дію: ";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    MySet setA;
    setA.Init(); // Порожня множина на старті

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nМножина А: ";
            setA.Display();
            break;

        case 2:
            cout << "\n---> Формування множини А:\n";
            setA.Read();
            break;

        case 3: {
            int el;
            cout << "Яке число додати (0-99)? ";
            cin >> el;
            if (setA.add(el)) cout << "Елемент " << el << " успішно додано.\n";
            else cout << "Помилка: Вихід за межі універсуму!\n";
            break;
        }

        case 4: {
            int el;
            cout << "Яке число вилучити (0-99)? ";
            cin >> el;
            if (setA.remove(el)) cout << "Елемент " << el << " вилучено.\n";
            else cout << "Помилка: Неприпустимий індекс!\n";
            break;
        }

        case 5: {
            MySet setB;
            cout << "\n---> Формування множини В для перетину:\n";
            setB.Read();
            MySet res = setA.intersectWith(setB);
            cout << "\nРезультат (А перетин В): ";
            res.Display();
            break;
        }

        case 6: {
            MySet setB;
            cout << "\n---> Формування множини В для об'єднання:\n";
            setB.Read();
            MySet res = setA.unionWith(setB);
            cout << "\nРезультат (А об'єднання В): ";
            res.Display();
            break;
        }

        case 7: {
            MySet setB;
            cout << "\n---> Формування множини В для різниці:\n";
            setB.Read();
            MySet res = setA.differenceWith(setB);
            cout << "\nРезультат (А мінус В): ";
            res.Display();
            break;
        }

        case 0:
            cout << "Завершення роботи...\n";
            break;

        default:
            cout << "Такої команди немає, спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}