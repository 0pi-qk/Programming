#include "list.h"
#include "database.h"
#include <iostream>
#include <conio.h>

using namespace std;

void list1() {
    list<int> lst;
    int num1, num2;
    bool out = true;
    while (out) {
        //system("cls");
        cout << "\t\tМеню" << endl;
        cout << "01| Добавить элемент в конец списка" << endl;
        cout << "02| Добавить элемент по номеру" << endl;
        cout << "03| Удалить элемент по номеру" << endl;
        cout << "04| Изменить элемент по номеру" << endl;
        cout << "05| Отсортировать список" << endl;
        cout << "06| Вывести элемент по номеру" << endl;
        cout << "07| Вывести список постранично" << endl;
        cout << "08| Вывести весь список" << endl;
        cout << "09| Очистить весь список" << endl;
        cout << "10| Сжать файл" << endl;
        cout << "11| Выйти из меню" << endl;
        cout << endl << "-> ";
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << "Введите новое значение: ";
            cin >> num1;
            lst.Add_to_file_end(num1);
            break;
        case 2:
            cout << "Введите новое значение: ";
            cin >> num1;
            cout << "Введите номер вставки: ";
            cin >> num2;
            try {
                lst.Add_to_file_by_num(num1, num2);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 3:
            cout << "Введите номер удаляемого значения: ";
            cin >> num1;
            try {
                lst.Del_from_file_by_num(num1);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 4:
            cout << "Введите новое значение: ";
            cin >> num1;
            cout << "Введите номер изменяемого значения: ";
            cin >> num2;
            try {
                lst.Edit_elem_by_num(num1, num2);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 5:
            try {
                lst.Sort();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 6:
            cout << "Введите номер элемента списка: ";
            cin >> num1;
            try {
                lst.Print_one_elem(num1);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 7:
        {
            int index = 0;
            while (out) {
                system("cls");
                cout << "\tПостраничный просмотр:" << endl;
                cout << "Текущая позиция: " << index << endl;
                cout << "Текущий элемент: ";
                try {
                    lst.Print_one_elem(index);
                }
                catch (indexoutofbounds& e) {
                    cerr << endl << "\tИсключение: " << e.what() << endl;
                    out = false;
                    system("pause");
                    break;
                }
                catch (nostructure& e) {
                    cerr << endl << "\tИсключение: " << e.what() << endl;
                    out = false;
                    system("pause");
                    break;
                }
                switch (_getch()) // ждёт нажатия на клавиатуру без Enter после этого
                {
                case 72: //вверх
                    out = false;
                    break;
                case 75: //влево
                    index--;
                    break;
                case 77: //вправо
                    index++;
                    break;
                }
            }
            out = true;
        }
        break;
        case 8:
            try {
                lst.Print_full_list();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 9:
            try {
                lst.Del_full_list_from_file();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 10:
            try {
                lst.Compress_file();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 11:
            out = false;
            break;
        default:
            break;
        }
    }
}

void list2() {
    list<database> lst;
    database db;
    int num1, num2;
    bool out = true;
    while (out) {
        system("cls");
        cout << "\t\tМеню" << endl;
        cout << "01| Добавить элемент в конец списка" << endl;
        cout << "02| Добавить элемент по номеру" << endl;
        cout << "03| Удалить элемент по номеру" << endl;
        cout << "04| Изменить элемент по номеру" << endl;
        cout << "05| Отсортировать список" << endl;
        cout << "06| Вывести элемент по номеру" << endl;
        cout << "07| Вывести список постранично" << endl;
        cout << "08| Вывести весь список" << endl;
        cout << "09| Очистить весь список" << endl;
        cout << "10| Вывести список неоплаченных заказов" << endl;
        cout << "11| Сжать файл" << endl;
        cout << "12| Выйти из меню" << endl;
        cout << endl << "-> ";
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << "\tВведите новую запись" << endl;
            cin >> db;
            lst.Add_to_file_end(db);
            break;
        case 2:
            cout << "\tВведите новую запись" << endl;
            cin >> db;
            cout << "Введите номер вставки: ";
            cin >> num2;
            try {
                lst.Add_to_file_by_num(db, num2);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 3:
            cout << "Введите номер удаляемого значения: ";
            cin >> num1;
            try {
                lst.Del_from_file_by_num(num1);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 4:
            cout << "\tВведите новую запись" << endl;
            cin >> db;
            cout << "Введите номер изменяемого значения: ";
            cin >> num2;
            try {
                lst.Edit_elem_by_num(db, num2);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 5:
            try {
                lst.Sort();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 6:
            cout << "Введите номер элемента списка: ";
            cin >> num1;
            try {
                cout << "    Город      |Код г| Тариф |    Дата    | Время |Продолжи| Номер тлф.  |Дата оплаты ";
                cout << endl;
                lst.Print_one_elem(num1);
            }
            catch (indexoutofbounds& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 7:
        {
            int index = 0;
            while (out) {
                system("cls");
                cout << "\tПостраничный просмотр:" << endl;
                cout << "Текущая позиция: " << index << endl;
                cout << "Текущий элемент: " << endl << endl;
                try {
                    cout << "    Город      |Код г| Тариф |    Дата    | Время |Продолжи| Номер тлф.  |Дата оплаты ";
                    cout << endl;
                    lst.Print_one_elem(index);
                }
                catch (indexoutofbounds& e) {
                    cerr << endl << "\tИсключение: " << e.what() << endl;
                    out = false;
                    system("pause");
                    break;
                }
                catch (nostructure& e) {
                    cerr << endl << "\tИсключение: " << e.what() << endl;
                    out = false;
                    system("pause");
                    break;
                }
                switch (_getch()) // ждёт нажатия на клавиатуру без Enter после этого
                {
                case 72: //вверх
                    out = false;
                    break;
                case 75: //влево
                    index--;
                    break;
                case 77: //вправо
                    index++;
                    break;
                }
            }
            out = true;
        }
        break;
        case 8:
            try {
                cout << "    Город      |Код г| Тариф |    Дата    | Время |Продолжи| Номер тлф.  |Дата оплаты ";
                cout << endl;
                lst.Print_full_list();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 9:
            try {
                lst.Del_full_list_from_file();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
                system("pause");
            }
            break;
        case 10:
            try {
                cout << "    Город      |Код г| Тариф |    Дата    | Время |Продолжи| Номер тлф.  | Дата оплаты | ДОЛГ" << endl;
                lst.NPL();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 11:
            try {
                lst.Compress_file();
            }
            catch (nostructure& e) {
                cerr << "\tИсключение: " << e.what() << endl;
            }
            system("pause");
            break;
        case 12:
            out = false;
            break;
        default:
            break;
        }
    }
}

int main(){
    system("chcp 65001");
    int num;
    bool out = true;
    while (out) {
        system("cls");
        cout << "Хранящиеся объекты:" << endl;
        cout << "1) int" << endl;
        cout << "2) database" << endl;
        cout << "3) Выйти из меню" << endl;
        cout << "-> ";
        cin >> num;
        if (num == 1)
            list1();
        if (num == 2)
            list2();
        if (num == 3)
            out = false;
    }
    return 0;
}