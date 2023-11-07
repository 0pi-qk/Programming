#include "list.h"
#include "Exception.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    system("chcp 65001");
    List my_list;
    int num1, num2, num3;
    bool out = true;
    while (out) {
        system("cls");
        cout << "\t\t\tМеню Списка:" << endl;
        cout << "01| Добавить новое значение" << endl;
        cout << "02| Добавить новое значение по номеру" << endl;
        cout << "03| Удалим последний элемент списка" << endl;
        cout << "04| Удалим элемент списка по номеру" << endl;
        cout << "05| Определим номер элемента по значению" << endl;
        cout << "06| Вывести весь список" << endl;
        cout << "07| Выйти из меню" << endl;
        cout << "08| Разделить первое комплексное число на второе" << endl;
        cout << "09| Вывод неинициализированного комплексного числа" << endl;
        cout << "10| Ошибка открытия файла" << endl;
        cout << "11| Ошибка чтения файла" << endl;
        cout << "12| Ошибка записи в файл" << endl;
        cout << endl << "-> ";
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << "Введите новое значение: ";
            cin >> num1 >> num2;
            my_list.addElement(new complex(num1, num2));
            break;
        case 2:
            cout << "Введите новое значение: ";
            cin >> num1 >> num2;
            cout << "Введите номер вставки: ";
            cin >> num3;
            try {
                my_list.addElementAfter(new complex(num1, num2), num3);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 3:
            try {
                my_list.deleteElement(my_list.getLength() - 1);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 4:
            cout << "Введите номер удаляемого значения: ";
            cin >> num2;
            try {
                my_list.deleteElement(num2);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 5:
            cout << "Введите значение: ";
            cin >> num1 >> num2;
            cout << my_list.find(new complex(num1, num2)) << endl;
            system("pause");
            break;
        case 6:
            try {
                my_list.printstruct();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 7:
            out = false;
            break;
        case 8:
            try {
                int d, m;
                complex c3;
                cout << "Введите первое комплексное число без i(Пример 7-4):" << endl;
                cin >> d >> m;
                complex c1(d, m);
                cout << "Введите второе комплексное число без i(Пример 3+2):" << endl;
                cin >> d >> m;
                complex c2(d, m);
                c3 = c1 / c2;
                cout << endl << "Частное: " << c3 << endl;
            }
            catch (difzero& e) {
                cerr <<"\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 9:
            try {
                complex c1;
                cout << c1;
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 10:
            try {
                ifstream input("q1.txt");
                if (input.fail()) throw fileopen("Ошибка открытия файла");
            }
            catch (fileopen& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 11:
            try {
                ifstream input("q2.txt");
                char line[256];
                input.getline(line, sizeof(line));
                if (input.fail()) throw fileread("Ошибка чтения файла");
            }
            catch (fileread& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 12:
            try {
                ofstream output("q3.txt", ios_base::in);
                if (output.fail()) throw filewrite("Ошибка записи в файл");
            }
            catch (filewrite& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        default:
            break;
        }
    }
    return 0;
}
