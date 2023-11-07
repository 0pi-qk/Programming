#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class complex {
private:
    double ds;  //действительная часть числа
    double mn;  //мнимая часть числа
    char* com = nullptr;  //строковое представление
    static int num;  //счетчик объектов класса
    static int KEY;  //тип результата
public:
    //консоль
    friend ostream& operator<<(ostream&, const complex&);
    friend istream& operator>>(istream&, complex&);
    //txt
    friend ofstream& operator<<(ofstream&, const complex&);
    friend ifstream& operator>>(ifstream&, complex&);
    //bin
    friend fstream& operator<<(fstream&, const complex&);
    friend fstream& operator>>(fstream&, complex&);
    friend complex operator*(const complex&, const complex&);
    friend complex operator/(const complex&, const complex&);
    friend bool operator==(const complex&, const complex&);
    void operator()();
    complex operator=(const complex&);
    complex();  //конструктор по умолчанию
    complex(double, double);  //конструктор с тремя параметрами
    complex(const complex&);  //конструктор копирования
    static void number();  //статическая функция - счетчик
    int GetNum();
    void plus(complex&, complex&);  //функция сложения комплексных чисел
    void minus(complex&, complex&);  //функция вычитания комплексных чисел
    char* get_com();
    ~complex();  //деструктор
    friend class list;
};

class copy_complex : public complex {  //производный класс, хранящий копию строки
private:
    double copy_ds;
    double copy_mn;
    char* copy_com;
public:
    copy_complex() :complex() {  //конструктор по умолчанию
        copy_com = NULL;
        copy_mn = 0;
        copy_ds = 0;
    }
    copy_complex(double x1, double x2) :complex(x1,x2) {  //конструктор с параметрами
        copy_com = new char[strlen(get_com()) + 1];
        strcpy(copy_com, get_com());
        begin_ds_mn();
    }
    void begin_ds_mn();  //перевод строки в действительную и мнимую части
    void to_string(double, double);  // перевод действительной и мнимой части в строку
    char* get_copy_com();  // вернуть копию строки
    double get_copy_ds();  // вернуть действительную часть
    double get_copy_mn();  // вернуть мнимую часть
    ~copy_complex() {  // деструктор
        if (copy_com) delete[]copy_com;  //если память занята, очищаем ее
    }
};

class date: public copy_complex {  // производный класс, хранящий дату создания объекта
private:
    int dd;
    int mm;
    int yy;
public:
    date() : copy_complex() {  //конструктор по умолчанию
        dd = 0;
        mm = 0;
        yy = 0;
    };
    date(int x1, int x2, int x3, double x4,double x5) : copy_complex(x4, x5) {  //конструктор с параметрами
        dd = x1;
        mm = x2;
        yy = x3;
    };
    void print_date(); //вывод даты на экран
};