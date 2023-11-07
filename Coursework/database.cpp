#include "database.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

database::database() {
    city[15] = NULL;
    num_city = -1;
    tariff = -1;
    date[11] = NULL;
    time[6] = NULL;
    duration = -1;
    phone_num[12] = NULL;
    date_pay[11] = NULL;
}

database::database(const char x1[15], int x2, double x3, const char x4[11], const char x5[6], double x6, const char x7[12], const char x8[11]){
    strcpy(city, x1);
    num_city = x2;
    tariff = x3;
    strcpy(date, x4);
    strcpy(time, x5);
    duration = x6;
    strcpy(phone_num, x7);
    if (x8 != NULL)
        strcpy(date_pay, x8);
}

database::~database() {
}

bool database::No_pay_list() {
    if (strcmp(this->date_pay, "NULL") == 0)
        return true;
    return false;
}

int database::Get_duration() {
    return this->duration;
}

double database::get_tariff() {
    return this->tariff;
}

int database::Get_quantity(double num) {
    int lenght = 0;
    string tmp = to_string(num);
    if (tmp[tmp.size() - 1] == '0')
        for (size_t i = tmp.size() - 1; tmp[i] == '0'; i--)
            tmp.erase(i, 1);
    if ((tmp[tmp.size() - 1] == '.') || (tmp[tmp.size() - 1] == ','))
        tmp.erase(tmp.size() - 1, 1);
    while (tmp[lenght] != '\0')
        lenght++;
    return lenght;
}

bool operator<(const database& c1, const database& c2)
{
    bool out = false;
    stringstream data;
    int d, m, y, rez_1, rez_2;
    data << c1.date[0] << c1.date[1];
    data >> d;
    data.clear();
    data << c1.date[3] << c1.date[4];
    data >> m;
    data.clear();
    data << c1.date[6] << c1.date[7] << c1.date[8] << c1.date[9];
    data >> y;
    data.clear();
    rez_1 = d + m * 31 + y * 365;
    data << c2.date[0] << c2.date[1];
    data >> d;
    data.clear();
    data << c2.date[3] << c2.date[4];
    data >> m;
    data.clear();
    data << c2.date[6] << c2.date[7] << c2.date[8] << c2.date[9];
    data >> y;
    data.clear();
    rez_2 = d + m * 31 + y * 365;
    if (rez_1 < rez_2)
        return true;
    return out;
}

ostream& operator<<(ostream& os, const database& TT) {
    database tmp;
    os << TT.city << setw(17 - strlen(TT.city)) << "| "
       << TT.num_city << setw(6 - tmp.Get_quantity(TT.num_city)) << "| "
       << TT.tariff << setw(8 - tmp.Get_quantity(TT.tariff)) << "| "
       << TT.date << setw(13 - strlen(TT.date)) << "| "
       << TT.time << setw(8 - strlen(TT.time)) << "| "
       << TT.duration << setw(9 - tmp.Get_quantity(TT.duration)) << "| "
       << TT.phone_num << setw(14 - strlen(TT.phone_num)) << "| "
       << TT.date_pay << setw(12 - strlen(TT.date_pay)) << " ";
    return os;
}

istream& operator>>(istream& is, database& TT) {
    cout << "Введите название города: ";
    is >> TT.city;
    cout << "Введите код города: ";
    is >> TT.num_city;
    cout << "Введите тариф: ";
    is >> TT.tariff;
    cout << "Введите дату звонка: ";
    is >> TT.date;
    cout << "Введите время начала вызова: ";
    is >> TT.time;
    cout << "Введите продолжительность: ";
    is >> TT.duration;
    cout << "Введите номер телефона: ";
    is >> TT.phone_num;
    cout << "Введите дату оплаты(NULL при отсутствии): ";
    is >> TT.date_pay;
    return is;
}

fstream& operator<<(fstream& os, const database& TT)
{
    int lenght= strlen(TT.city) + 1;
    int Size_stream = 0;
    Size_stream += sizeof(int);
    os.write((char*)&lenght, sizeof(int));
    Size_stream += lenght;
    os.write(TT.city, lenght);
    Size_stream += sizeof(int);
    os.write((char*)&TT.num_city, sizeof(int));
    Size_stream += sizeof(double);
    os.write((char*)&TT.tariff, sizeof(double));
    lenght= strlen(TT.date) + 1;
    Size_stream += sizeof(int);
    os.write((char*)&lenght, sizeof(int));
    Size_stream += lenght;
    os.write(TT.date, lenght);
    lenght= strlen(TT.time) + 1;
    Size_stream += sizeof(int);
    os.write((char*)&lenght, sizeof(int));
    Size_stream += lenght;
    os.write(TT.time, lenght);
    Size_stream += sizeof(double);
    os.write((char*)&TT.duration, sizeof(double));
    lenght= strlen(TT.phone_num) + 1;
    Size_stream += sizeof(int);
    os.write((char*)&lenght, sizeof(int));
    Size_stream += lenght;
    os.write(TT.phone_num, lenght);
    lenght= strlen(TT.date_pay) + 1;
    Size_stream += sizeof(int);
    os.write((char*)&lenght, sizeof(int));
    Size_stream += lenght;
    os.write(TT.date_pay, lenght + (100 - Size_stream));
    return os;
}

fstream& operator>>(fstream& is, database& TT) {
    int len;
    is.read((char*)&len, sizeof(int));
    is.read(TT.city, len);
    is.read((char*)&TT.num_city, sizeof(int));
    is.read((char*)&TT.tariff, sizeof(double));
    is.read((char*)&len, sizeof(int));
    is.read(TT.date, len);
    is.read((char*)&len, sizeof(int));
    is.read(TT.time, len);
    is.read((char*)&TT.duration, sizeof(double));
    is.read((char*)&len, sizeof(int));
    is.read(TT.phone_num, len);
    is.read((char*)&len, sizeof(int));
    is.read(TT.date_pay, len);
    return is;
}