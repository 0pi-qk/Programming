#include "complex.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    system("chcp 65001");  //РЯ
    int d, m, dd, mm, yy;
    cout << "Введите дату(Пример 12 07 2014):" << endl;
    cin >> dd >> mm >> yy;
    cout << "Введите комплексное число без i(Пример 7-4):" << endl;
    cin >> d >> m;
    date dat(dd, mm, yy, d, m);
    cout << endl << "Введенные данные:" << endl << "Дата:  ";
    dat.print_date();
    cout << "Комплексное число:  " << dat << endl;
    cout << "Копия комплексного числа:  " << dat.get_copy_com() << endl;
    cout << "Целая часть копии комплексного числа:  " << dat.get_copy_ds() << endl;
    cout << "Мнимая часть копии комплексного числа:  " << dat.get_copy_mn() << endl;
    dat.to_string(99, -7);
    cout << "Сформируем новое комплексное число в копии с параметрами 99-7i:  " << dat.get_copy_com();
}