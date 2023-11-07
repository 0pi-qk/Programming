#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

void list1() {  //для int
    List<int> my_list;
    int num1, num2;
    bool out = true;
    while (out) {
        system("cls");
        cout << "\t\t\tМеню Списка:" << endl;
        cout << "1| Добавить новое значение" << endl;
        cout << "2| Добавить новое значение по номеру" << endl;
        cout << "3| Удалим последний элемент списка" << endl;
        cout << "4| Удалим элемент списка по номеру" << endl;
        cout << "5| определим номер элемента по значению" << endl;
        cout << "6| Вывести весь список" << endl;
        cout << "7| Выйти из меню" << endl;
        cout << endl << "-> ";
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << "Введите новое значение: ";
            cin >> num1;
            my_list.addElement(num1);
            break;
        case 2:
            cout << "Введите новое значение: ";
            cin >> num1;
            cout << "Введите номер вставки: ";
            cin >> num2;
            my_list.addElementAfter(num1, num2);
            break;
        case 3:
            my_list.deleteElement(my_list.getLength() - 1);
            break;
        case 4:
            cout << "Введите номер удаляемого значения: ";
            cin >> num2;
            my_list.deleteElement(num2);
            break;
        case 5:
            cout << "Введите значение: ";
            cin >> num1;
            cout << my_list.find(num1) << endl;
            system("pause");
            break;
        case 6:
            my_list.printstruct();
            cout << endl;
            system("pause");
            break;
        case 7:
            out = false;
            break;
        default:
            break;
        }
    }
}

void list2() {  //для complex
    List<complex> my_list;
    int num1, num2, num3;
    bool out = true;
    while (out) {
        system("cls");
        cout << "\t\t\tМеню Списка:" << endl;
        cout << "1| Добавить новое значение" << endl;
        cout << "2| Добавить новое значение по номеру" << endl;
        cout << "3| Удалим последний элемент списка" << endl;
        cout << "4| Удалим элемент списка по номеру" << endl;
        cout << "5| Определим номер элемента по значению" << endl;
        cout << "6| Вывести весь список" << endl;
        cout << "7| Выйти из меню" << endl;
        cout << endl << "-> ";
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << "Введите новое значение: ";
            cin >> num1 >> num2;
            my_list.addElement(complex(num1, num2));
            break;
        case 2:
            cout << "Введите новое значение: ";
            cin >> num1 >> num2;
            cout << "Введите номер вставки: ";
            cin >> num3;
            my_list.addElementAfter(complex(num1, num2), num3);
            break;
        case 3:
            my_list.deleteElement(my_list.getLength() - 1);
            break;
        case 4:
            cout << "Введите номер удаляемого значения: ";
            cin >> num2;
            my_list.deleteElement(num2);
            break;
        case 5:
            cout << "Введите значение: ";
            cin >> num1 >> num2;
            cout << my_list.find(complex(num1, num2)) << endl;
            system("pause");
            break;
        case 6:
            my_list.printstruct();
            cout << endl;
            system("pause");
            break;
        case 7:
            out = false;
            break;
        default:
            break;
        }
    }
}

int main() {
    system("chcp 65001");  //РЯ
    cout << "Хранящиеся объекты:" << endl << "1) int" << endl << "2) complex" << endl<< "-> ";
    int num;
    cin >> num;
    if (num == 1)
        list1();
    else
        list2();
    return 0;
}
