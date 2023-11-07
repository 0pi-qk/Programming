#include "complex.h"
#include "Exception.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

int complex::num = 0;  //задаем значение статической переменной num
int complex::KEY = 1;  // 1 - алгебраическая 
// 2 - тригонометрическая

ostream& operator<<(ostream& os, const complex& c) {
    if (c.com == NULL)
        throw nostructure("Структура пуста");
    os << c.com;
    return os;
}

istream& operator>>(istream& is, complex& c) {
    is >> c.ds >> c.mn;
    c.operator()();
    return is;
}

ofstream& operator<<(ofstream& os, const complex& c) {
    os << c.ds << " " << c.mn << " " << c.com << endl;
    return os;
}

ifstream& operator>>(ifstream& is, complex& c) {
    char tmp[100];
    is >> c.ds >> c.mn >> tmp;
    if (c.com != NULL) delete[] c.com;
    c.com = new char[strlen(tmp) + 1];
    strcpy(c.com, tmp);
    is.get();
    return is;
}

fstream& operator<<(fstream& os, const complex& c) {
    int len = strlen(c.com) + 1;
    os.write((char*)&len, sizeof(int));
    os.write((char*)&c.ds, sizeof(double));
    os.write((char*)&c.mn, sizeof(double));
    os.write(c.com, len);
    os << endl;
    return os;
}

fstream& operator>>(fstream& is, complex& c) {
    int len;
    is.read((char*)&len, sizeof(int));
    is.read((char*)&c.ds, sizeof(double));
    is.read((char*)&c.mn, sizeof(double));
    if (c.com) delete[] c.com;
    c.com = new char[len];
    is.read(c.com, len);
    is.get();
    return is;
}

complex operator*(const complex& c1, const complex& c2) {
    complex rez;
    rez.ds = (c1.ds * c2.ds) - (c1.mn * c2.mn);  //находим действительную часть
    rez.mn = (c1.mn * c2.ds) + (c1.ds * c2.mn);  //находим мнимую часть
    rez();
    return rez;
}

complex operator/(const complex& c1, const complex& c2) {
    complex rez;
    if ((c2.ds == 0) && (c2.mn == 0))
        throw difzero("Нельзя делить на ноль");
    else {
        rez.ds = ((c1.ds * c2.ds) + (c1.mn * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим действительную часть
        rez.mn = ((c1.mn * c2.ds) - (c1.ds * c2.mn)) / (pow(c2.ds, 2) + (pow(c2.mn, 2)));  //находим мнимую часть
        rez();
    }
    return rez;
}

bool operator==(const complex& c1, const complex& c2) {
    if ((c1.ds == c2.ds) && (c1.mn == c2.mn))
        return true;
    else
        return false;
}

void complex::operator()() {
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
    if (com != nullptr) {  //выделение памяти
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
}

complex complex::operator=(const complex& c) {
    if (this == &c) return *this;
    if (com != NULL) delete[]com;
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
    this -> operator()();
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

int complex::GetNum() {
    return num;
}

void complex::plus(complex& c1, complex& c2) {  //функция сложения комплексных чисел
    ds = c1.ds + c2.ds;  //находим действительную часть
    mn = c1.mn + c2.mn;  //находим мнимую часть
    this -> operator()();
}

void complex::minus(complex& c1, complex& c2) {  //функция вычитания комплексных чисел
    ds = c1.ds - c2.ds;  //находим действительную часть
    mn = c1.mn - c2.mn;  //находим мнимую часть
    this -> operator()();
}

complex::~complex() {       //очистка памяти   
    if (com) delete[]com;  //если память задействована, то очищаем ее
    num--;
}

char* complex::get_com() {
    return com;
}

void copy_complex::begin_ds_mn() {
    bool k = false;
    stringstream d, m;
    for (int i = 0; copy_com[i] != '\0'; i++) {
        if ((copy_com[i] == '-') || (copy_com[i] == '+'))
            k = true;
        if (k == false)
            d << copy_com[i];
        if (k == true)
            m << copy_com[i];
    }
    d >> copy_ds;
    m >> copy_mn;
}

void copy_complex::to_string(double x1, double x2) {
    stringstream txt;
    int lenght = 0;
    if (x1 == 0 && x2 == 0)
        txt << 0 << endl;
    if (x2 == 0)
        txt << x1 << endl;
    if (x2 < 0) {
        if (x2 == -1)
            if (x1 == 0)
                txt << "-i" << endl;
            else
                txt << x1 << "-i" << endl;
        else
        if (x1 == 0)
            txt << x2 << "i" << endl;
        else
            txt << x1 << x2 << "i" << endl;
    }
    else {
        if (x2 == 1)
            if (x1 == 0)
                txt << "i" << endl;
            else
                txt << x1 << "+i" << endl;
        else
        if (x1 == 0)
            txt << x2 << "i" << endl;
        else
            txt << x1 << "+" << x2 << "i" << endl;
    }
    lenght = size(txt.str());
    if (copy_com != NULL) {  //выделение памяти 
        if (lenght == strlen(copy_com))
            txt >> copy_com;
        else {
            delete[]copy_com;
            copy_com = new char[lenght];
            txt >> copy_com;
        }
    }
    else {
        copy_com = new char[lenght];
        txt >> copy_com;
    }
}

char* copy_complex::get_copy_com() {
    return copy_com;
}

double copy_complex::get_copy_ds() {
    return copy_ds;
}

double copy_complex::get_copy_mn() {
    return copy_mn;
}

void date::print_date() {
    if (dd < 10 && dd > 0)
        if (mm < 10 && mm > 0)
            cout << "0" << dd << ".0" << mm << "." << yy << endl;
        else
            cout << "0" << dd << "." << mm << "." << yy << endl;
    else if (mm < 10 && mm > 0)
        cout << dd << ".0" << mm << "." << yy << endl;
    else
        cout << dd << "." << mm << "." << yy << endl;
}