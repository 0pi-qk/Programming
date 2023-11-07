#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//выход за границы
class indexoutofbounds : public std::invalid_argument
{
public:
    indexoutofbounds(const char* message) : std::invalid_argument(message)
    {
    }
};

//список пуст
class nostructure : public std::invalid_argument
{
public:
    nostructure(const char* message) : std::invalid_argument(message)
    {
    }
};

template <typename T>
class Element {
public:
    T content;
    Element<T>* Next;

};

template <typename T>
class list
{
    Element<T>* Head = NULL; // Адрес головного элемента списка
    int count = 0; // Количество элементов списка
public:
    int Get_file_lenght();  //вернуть размерность файла
    int Get_string_lenght();  //вернуть размерность строки
    int Get_file_count();  // вернуть количество элементов в файле
    void Add_to_file_end(T);  //добавить в конец файла
    void Add_to_file_by_num(T, int);  //добавить по индексу в файл
    void Del_full_list_from_file();  //очисть весь файл
    void Del_from_file_by_num(int);  //удалить из файла по индексу
    T Get_from_file(int);  //получить значение из файла по индексу
    void Edit_elem_by_num(T, int);//Изменение элемента
    void Sort();//сортировка
    void Print_one_elem(int);// Вывести один элемент
    void Print_full_list();// Вывести весь список
    void NPL();//список неоплаченных заказов
    void Compress_file();  //Сжатие файла
    int Get_count();// Вернуть количество элементов списка
    void Add_elem_end(T);//Добавить элемент(в конец)
    void Add_elem_by_num(T, int); //Добавить элемент по номеру
    void Del_full_list();//Очистить весь список
    void Del_elem_by_num(int);// Удалить по номеру
    friend fstream& operator<<(fstream&, const int&);
    friend fstream& operator>>(fstream&, int&);
    T& operator[](int);
};

template <typename T>
void list<T>::Compress_file() {  //сжатие файла
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    cout << "Начальная емкость файла: " << Get_file_lenght() << endl;
    fstream in("Database.bin", ios_base::in | ios_base::binary);
    fstream out("Database_compress.bin", ios::binary | ios::out);
    char    symbol;
    int     num = 0;
    while (!in.eof()) {
        symbol = in.get();
        num++;
        if (symbol != in.peek()) {
            if (num > 1)
                out << (char)(num - 128) << symbol;
            else
                out << symbol;
            num = 0;
        }
        else if (num == 127) {
            out << (char)(num - 128) << symbol;
            num = 0;
        }
    }
    in.close();
    cout << "Полученная емкость файла: " << out.tellg() << endl;
    out.close();
}

fstream& operator<<(fstream& os, const int& TT)
{
    os.write((char*)&TT, 8);
    return os;
}

fstream& operator>>(fstream& is, int& TT)
{
    is.read((char*)&TT, sizeof(int));
    is.get();
    return is;
}

template <typename T>
T& list<T>::operator[](int index) {
    Element<T>* tmp = Head;
    for (int i = 0; i < index; i += 1)
        tmp = tmp->Next;
    return tmp->content;
}

template <typename T>
int list<T>::Get_file_lenght() {  //размер файла
    int lenght = 0;
    fstream file("Database.bin", ios_base::in | ios_base::binary);
    file.seekg(0, std::ios::end);
    lenght = file.tellg();
    file.close();
    return lenght;
}

template <typename T>
int list<T>::Get_string_lenght() {  //размер строки
    int lenght = 0;
    fstream file("Database.bin", ios_base::in | ios_base::binary);
    string tmp;
    getline(file, tmp);
    lenght = tmp.length();
    file.close();
    return lenght;
}

template <typename T>
int list<T>::Get_file_count() {  //количество элементов в файле
    return Get_file_lenght() / (Get_string_lenght() + 1);
}

template <typename T>
void list<T>::Add_to_file_end(T content) {//добавить в конец файла
    cout<<"L = "<<Get_file_count();
    Add_to_file_by_num(content, Get_file_count());
}

template <typename T>
void list<T>::Add_to_file_by_num(T content, int index) {  //добавить в файл по номеру
    if ((index < 0) || (index > Get_file_count()))
        throw indexoutofbounds("Выход за пределы списка");
    fstream out;
    list<T> lst;
    lst.Add_elem_end(content);
    if (index * (Get_string_lenght() + 1) == Get_file_lenght()) {
        out.open("Database.bin", ios_base::app | ios_base::binary);
        out << lst[0] << endl;
        lst.Del_full_list();
    }
    else {
        out.open("Database.bin", ios::binary | ios::out | ios::in);
        for (int ind = index, num_step = Get_file_count() + 1; ind < num_step; ind++) {
            lst.Add_elem_end(Get_from_file(ind));
            out.seekp(ind * (Get_string_lenght() + 1), ios::beg);
            out << lst[0] << endl;
            lst.Del_elem_by_num(0);
        }
    }
    out.close();
}

template <typename T>
void list<T>::Del_full_list_from_file() {//очистить весь файл
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    fstream out("Database.bin", ios_base::out | ios_base::trunc | ios_base::binary);
    out.close();
}

template <typename T>
void list<T>::Del_from_file_by_num(int index) {  //удалить из файла по номеру
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    if ((index < 0) || (index > Get_file_count() - 1))
        throw indexoutofbounds("Выход за пределы списка");
    fstream out("Database.bin", ios::binary | ios::out | ios::in);
    list<T> lst;
    int num_step = Get_file_count() - 1;
    if (index * (Get_string_lenght() + 1) != Get_file_lenght())
        for (int ind = index; ind < num_step; ind++) {
            lst.Add_elem_end(Get_from_file(ind + 1));
            out.seekp(ind * (Get_string_lenght() + 1), ios::beg);
            out << lst[0] << endl;
            lst.Del_full_list();
        }
    for (int ind = 0; ind < num_step; ind++) {
        lst.Add_elem_end(Get_from_file(ind));
    }
    out.close();
    Del_full_list_from_file();
    for (int ind = 0; ind <= num_step - 1; ind++)
        lst.Add_to_file_end(lst[ind]);
    lst.Del_full_list();
}

template <typename T>
T list<T>::Get_from_file(int index) { //получить значение из файла
    fstream in("Database.bin", ios_base::in | ios_base::binary);
    in.seekg(index * (Get_string_lenght() + 1), ios::beg);
    T tmp;
    in >> tmp;
    in.close();
    return tmp;
}

template <typename T>
void list<T>::Edit_elem_by_num(T content, int index) {//Изменить элемент
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    if ((index < 0) || (index > Get_file_count() - 1))
        throw indexoutofbounds("Выход за пределы списка");
    fstream out("Database.bin", ios::binary | ios::out | ios::in);
    list<T> lst;
    int num_step = Get_file_count() - 1;
    if (index * (Get_string_lenght() + 1) != Get_file_lenght())
        for (int ind = index; ind < num_step; ind++) {
            lst.Add_elem_end(Get_from_file(ind + 1));
            out.seekp(ind * (Get_string_lenght() + 1), ios::beg);
            out << lst[0] << endl;
            lst.Del_full_list();
        }
    lst.Add_elem_end(content);
    out << lst[0] << endl;
    lst.Del_full_list();
    out.close();
}

template <typename T>
void list<T>::Sort() {//сортировка выбором
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    list<T> lst;
    int num_step = Get_file_count();
    for (int ind = 0; ind < num_step; ind++)
        lst.Add_elem_end(Get_from_file(ind));
    for (int ind_1 = 0; ind_1 < num_step - 1; ind_1++)
        for (int ind_2 = ind_1 + 1; ind_2 < num_step; ind_2++)
            if (lst[ind_2] < lst[ind_1]) {
                T tmp = lst[ind_1];
                lst[ind_1] = lst[ind_2];
                lst[ind_2] = tmp;
            }
    Del_full_list_from_file();
    for (int ind = 0; ind < num_step; ind++)
        lst.Add_to_file_end(lst[ind]);
    lst.Del_full_list();
}

template <typename T>
void list<T>::Print_one_elem(int index) {//Вывести один элемент из файла
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    if ((index < 0) || (index > Get_file_count() - 1))
        throw indexoutofbounds("Выход за пределы списка");
    cout << Get_from_file(index) << endl;
}

template <typename T>
void list<T>::Print_full_list()  //вывести весь список
{
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    for (int index = 0; index < Get_file_count(); index++)
        Print_one_elem(index);
}

template <typename T>
void list<T>::NPL() {//список неоплаченных заказов
    if (Get_file_count() == 0)
        throw nostructure("Список пуст");
    fstream out("Database.bin", ios::binary | ios::out | ios::in);
    list<T> lst;
    double sum_now;
    for (int i = 0; i < Get_file_count(); i++) {
        lst.Add_elem_end(Get_from_file(i));
        Element<T>* tmp = lst.Head;
        if (tmp->content.No_pay_list()) {
            sum_now = tmp->content.Get_duration() * tmp->content.get_tariff();
            cout << tmp->content << "| " << sum_now << endl;
        }
        lst.Del_full_list();
    }
}

template <typename T>
int list<T>::Get_count() { //размерность списка
    return count;
}

template <typename T>
void list<T>::Add_elem_end(T content) {//добавить новый элемент в конец списка
    Add_elem_by_num(content, Get_count());
}

template <typename T>
void list<T>::Add_elem_by_num(T content, int index) {//добавить новый элемент в список по номеру
    count++;
    if (index == 0) {
        Element<T>* tmp = new Element<T>;
        tmp->content = content;
        tmp->Next = this->Head;
        this->Head = tmp;
        return;
    }
    Element<T>* curr = this->Head;
    for (int i = 0; curr; ) {
        i++;
        if (index == i)
        {
            Element<T>* tmp = new Element<T>;
            tmp->content = content;
            tmp->Next = curr->Next;
            curr->Next = tmp;
        }
        curr = curr->Next;
    }
}

template <typename T>
void list<T>::Del_full_list() { //Очисть весь список
    int lenght = Get_count();
    for (int index = 0; index < lenght; index++)
        Del_elem_by_num(0);
}

template <typename T>
void list<T>::Del_elem_by_num(int index) {//удалить элемент из списка по номеру
    Element<T>* tmp = Head, * helping = Head;
    for (int i = 0; i < index; i++) {
        helping = tmp;
        tmp = tmp->Next;
    }
    if (tmp == Head)
        Head = tmp->Next;
    else
        helping->Next = tmp->Next;
    delete tmp;
    count--;
}