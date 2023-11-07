#include "complex.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int complex::num = 0;  //задаем значение статической переменной num
int complex::KEY = 1;  // 1 - алгебраическая 
// 2 - тригонометрическая

complex operator*(const complex& c1, const complex& c2) {
    complex rez;
    rez.ds = (c1.ds * c2.ds) - (c1.mn * c2.mn);  //находим действительную часть
    rez.mn = (c1.mn * c2.ds) + (c1.ds * c2.mn);  //находим мнимую часть
    rez(1);
    return rez;
}

complex operator/(const complex& c1, const complex& c2) {
    complex rez;
    if ((c2.ds == 0) && (c2.mn == 0))
        cout << "Частное: error" << endl;
    else {
        rez.ds = ((c1.ds * c2.ds) + (c1.mn * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим действительную часть
        rez.mn = ((c1.mn * c2.ds) - (c1.ds * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим мнимую часть
        rez(1);
    }
    return rez;
}

bool operator==(const complex& c1, const complex& c2) {
    if ((c1.ds == c2.ds) && (c1.mn == c2.mn))
        return true;
    else
        return false;
}

void complex::operator()(int key) {
    stringstream txt;
    double r = sqrt(pow(ds, 2) + pow(mn, 2)), fi = atan(mn / ds);
    int lenght = 0;
    if (KEY == 1) {
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
        lenght = size(txt.str());
    }
    else if (KEY == 2) {
        if (ds >= 0) {  //1 4
            if (fi < 0)
                txt << r << "[cos(" << abs(fi) << ")-Isin(" << abs(fi) << ")]";
            else
                txt << r << "[cos(" << fi << ")+Isin(" << fi << ")]";
        }
        if ((ds < 0) && (mn >= 0)) { //2
            fi += 3.14;
            if (fi < 0)
                txt << sqrt(pow(ds, 2) + pow(mn, 2)) << "[cos(" << abs(fi) << ")-Isin(" << abs(fi) << ")]";
            else
                txt << sqrt(pow(ds, 2) + pow(mn, 2)) << "[cos(" << fi << ")+Isin(" << fi << ")]";
        }
        if ((ds < 0) && (mn <= 0)) { //3
            fi -= 3.14;
            if (fi < 0)
                txt << r << "[cos(" << abs(fi) << ")-Isin(" << abs(fi) << ")]";
            else
                txt << r << "[cos(" << fi << ")+Isin(" << fi << ")]";
        }
        lenght = 1 + size(txt.str());

    }
    else
        return;
    if (com != NULL) {  //выделение памяти 
        if (lenght == strlen(com))
            txt >> com;
        else {
            delete[]com;
            com = new char[lenght];
            txt >> com;
        }
    }
    else {
        com = new char[lenght];
        txt >> com;
    }
    if (key != 0)
        cout << com;
}

complex complex::operator=(const complex& c) {
    if (this == &c) return *this;
    if (com) delete[]com;
    com = new char[strlen(c.com) + 1];  //выделяем память
    strcpy(com, c.com);
    ds = c.ds;
    mn = c.mn;
    return *this;
}

complex::complex() {  //Конструктор по умолчанию
    ds = 0;
    mn = 0;
    com = NULL;
    number();
}

complex::complex(double a, double b) { //конструктор с двумя параметрами                                 
    ds = a;                          //(задает значения переменных объекта, введенные с клавиатуры)
    mn = b;
    this -> operator()(0);
    number();
}

complex::complex(const complex& obj) {  //конструктор копирования
    ds = obj.ds;
    mn = obj.mn;
    com = new char[strlen(obj.com)+1];  //выделяем память
    strcpy(com, obj.com);
}

void complex::number(){  //статическая функция - счетчик
    num++;
}

void complex::plus(complex& c1, complex& c2) {  //функция сложения комплексных чисел
    ds = c1.ds + c2.ds;  //находим действительную часть
    mn = c1.mn + c2.mn;  //находим мнимую часть
    this -> operator()(1);
}

void complex::minus(complex& c1, complex& c2) {  //функция вычитания комплексных чисел
    ds = c1.ds - c2.ds;  //находим действительную часть
    mn = c1.mn - c2.mn;  //находим мнимую часть
    this -> operator()(1);
}

complex::~complex() {       //очистка памяти   
    if (com) delete[]com;  //если память задействована, то очищаем ее
}