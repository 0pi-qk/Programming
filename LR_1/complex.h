class complex {
private:
    float ds;  //действительная часть числа
    float mn;  //мнимая часть числа
    char* com;  //строковое представление
    static int num;  //счетчик объектов класса
public:
    complex();  //конструктор по умолчанию
    complex(float, float);  //конструктор с тремя параметрами
    complex(const complex&);  //конструктор копирования
    static void number();  //статическая функция - счетчик
    void qq();  //функция работы с памятью
    void out(char*);  //функция вывода на экран
    void plus(complex&, complex&);  //функциия сложения комплексных чисел
    void minus(complex&, complex&);  //функциия вычитания комплексных чисел
    void times(complex&, complex&);  //функциия умножения комплексных чисел
    void divided(complex&, complex&);  //функциия деления комплексных чисел
    ~complex();  //деструктор
};