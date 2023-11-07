#include <iostream>
#include <fstream>

using namespace std;

class complex {
private:
    double ds;  //действительная часть числа
    double mn;  //мнимая часть числа
    char* com;  //строковое представление
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
    ~complex();  //деструктор
};