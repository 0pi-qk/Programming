
class complex {
private:
    double ds;  //действительная часть числа
    double mn;  //мнимая часть числа
    char* com;  //строковое представление
    static int num;  //счетчик объектов класса
    static int KEY;  //тип результата
public:
    friend complex operator*(const complex&, const complex&); //перегрузка оператора умножения дружественной функцией
    friend complex operator/(const complex&, const complex&);//перегрузка оператора деления дружественной функцией
    friend bool operator==(const complex&, const complex&);//перегрузка оператора сравнения дружественной функцией
    void operator()(int);
    complex operator=(const complex&);
    complex();  //конструктор по умолчанию
    complex(double, double);  //конструктор с двумя параметрами
    complex(const complex&);  //конструктор копирования
    static void number();  //статическая функция - счетчик
    void plus(complex&, complex&);  //функция сложения комплексных чисел
    void minus(complex&, complex&);  //функция вычитания комплексных чисел
    ~complex();  //деструктор
};