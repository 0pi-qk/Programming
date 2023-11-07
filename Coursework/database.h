#include <iostream>
#include <fstream>

using namespace std;

class database
{
    char city[15];
    int num_city;
    double tariff;
    char date[11];
    char time[6];
    double duration;
    char phone_num[12];
    char date_pay[11];
public:
    database();
    database(const char[15], int, double, const char[11], const char[6], double, const char[12], const char[11]);
    ~database();
    bool No_pay_list(); //проверка оплачен ли звонок
    int Get_duration();  //получить продолжительность звонка
    double get_tariff(); //получить тариф
    int Get_quantity(double);  //количество цифр в числе
    friend bool operator<(const database& c1, const database& c2);
    friend ostream& operator<<(ostream&, const database&);
    friend istream& operator>>(istream&, database&);
    friend fstream& operator<<(fstream&, const database&);
    friend fstream& operator>>(fstream&, database&);
};

