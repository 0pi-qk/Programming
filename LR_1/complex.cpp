#include "complex.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

int complex::num = 0;  //задаем значение статической переменной num

complex::complex() {  //Конструктор по умолчанию
    ds = 0;
    mn = 0;
    com = NULL;
    number();  //*2)Вызывается функция счетчик*
}

complex::complex(float a, float b) { //конструктор с двумя параметрами                                 
    ds = a;                          //(задает значения переменных объекта, введенные с клавиатуры)
    mn = b;
    com = NULL;
    number();  //*4, 6)Вызывается функция счетчик*
}

complex::complex(const complex& obj) {  //конструктор копирования
    ds = obj.ds;
    mn = obj.mn;
    com = new char[strlen(obj.com)];  //выделяем память
    strcpy(com, obj.com);
}

void complex::number(){  //статическая функция - счетчик
    num++;
}

void complex::qq() { //функция для работы с динамической памятью, вывод результата на экран
    stringstream txt;
    /*в строках с 41 по 68 происходит запись получившегося комплексного числа в зависимости от конкретных случаев:
    "особые" случаи: 0+-0i -> 0; 0+-1i ->+-i; 1+-0i -> 1; 1+-1i -> 1+-i,
    а также обычная запись комплексного числа +-3+-9i*/
    if (ds == 0 && mn == 0)
        txt << 0 << endl;
    if (mn == 0)
        txt << ds << endl;
    if (mn < 0) {
        if (mn == -1)
            if (ds == 0)
                txt << "-i" << endl;
            else
                txt << ds << "-i" << endl;
        else
        if (ds == 0)
            txt << mn << "i" << endl;
        else
            txt << ds << mn << "i" << endl;
    }
    else {
        if (mn == 1)
            if (ds == 0)
                txt << "i" << endl;
            else
                txt << ds << "+i" << endl;
        else
        if (ds == 0)
            txt << mn << "i" << endl;
        else
            txt << ds << "+" << mn << "i" << endl;
    }
    if (com != NULL) {  //выделение памяти 
        if (size(txt.str()) > strlen(com)) {
            com = new char[size(txt.str())];
            txt >> com;
        }
        else if (size(txt.str()) == strlen(com))
            txt >> com;
        else {
            delete[]com;
            com = new char[size(txt.str())];
            txt >> com;
        }
    }
    else {
        com = new char[size(txt.str())];
        txt >> com;
    }
    out(com);  //*9, 12, 15, 18)Вызывается функция вывода на экран*
}

void complex::out(char* c) {  //функция вывода результата на экран
    cout << c << endl;  //выводим результат на экран
}

void complex::plus(complex& c1, complex& c2) {  //функция сложения комплексных чисел
    ds = c1.ds + c2.ds;  //находим действительную часть
    mn = c1.mn + c2.mn;  //находим мнимую часть
    cout << "Сумма: ";  //выводим в консоль название операции
    qq(); //*8)Вызывается функция работы с памятью*
}

void complex::minus(complex& c1, complex& c2) {  //функция вычитания комплексных чисел
    ds = c1.ds - c2.ds;  //находим действительную часть
    mn = c1.mn - c2.mn;  //находим мнимую часть
    cout << "Разность: ";  //выводим в консоль название операции
    qq();  //*11)Вызывается функция работы с памятью*
}

void complex::times(complex& c1, complex& c2) {  //функция умножения комплексных чисел
    ds = (c1.ds * c2.ds) - (c1.mn * c2.mn);  //находим действительную часть
    mn = (c1.mn * c2.ds) + (c1.ds * c2.mn);  //находим мнимую часть
    cout << "Произведение: ";  //выводим в консоль название операции
    qq();//*14)Вызывается функция работы с памятью*
}

void complex::divided(complex& c1, complex& c2) { //функция деления комплексных чисел
    if ((c2.ds == 0) && (c2.mn == 0))
        cout << "Частное: error";
    else {
        ds = ((c1.ds * c2.ds) + (c1.mn * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим действительную часть
        mn = ((c1.mn * c2.ds) - (c1.ds * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим мнимую часть
        cout << "Частное: ";  //выводим в консоль название операции
        qq();//*17)Вызывается функция работы с памятью*
    }
}

complex::~complex() {       //очистка памяти   
    if (com) delete[]com;  //если память задействована, то очищаем ее
}