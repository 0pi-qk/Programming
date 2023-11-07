#include "complex.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    system("chcp 65001");  //РЯ
    int N = 0, x, y;
    ifstream in_num("NUM.txt", ios::in);
    in_num >> N;
    in_num.close();
    complex* arr = new complex[N + 7];
    ifstream in_txt("TXT.txt", ios::in);
    for (int i = 0; i < N; i++)
        in_txt >> arr[i];
    in_txt.close();
    fstream in_bin("BINARY.txt", ios::binary | ios::in);
    for (int i = 0; i < N; i++)
        in_bin >> arr[i];
    in_bin.close();
    cout << "Введите первое комплексное число без i(Пример 7-4):" << endl;
    cin >> arr[N]; x = N; N++;
    cout << "Введите второе комплексное числобез i(Пример 3+2):" << endl;
    cin >> arr[N]; y = N; N++;
    arr[N] = arr[x];
    cout << "Присвоим значение объекта с1: " << arr[x] << " объекту c3-> " << arr[N]; N++;
    cout << endl << "Сумма: ";
    arr[N].plus(arr[x], arr[y]);
    cout << arr[N] << endl << "Разность: "; N++;
    arr[N].minus(arr[x], arr[y]);
    cout << arr[N] << endl << "Произведение: "; N++;
    arr[N] = arr[x] * arr[y];
    cout << arr[N] << endl << "Частное: "; N++;
    arr[N] = arr[x] / arr[y];
    cout << arr[N] << endl << "Сравнение " << arr[x] << " и " << arr[y] << ": "; N++;
    if (arr[x] == arr[y])
        cout << "Комплексные числа равны" << endl;
    else
        cout << "Комплексные числа не равны" << endl;
    ofstream Out_txt("TXT.txt", ios::out | ios::trunc);
    for (int i = 0; i < N; i++)
        Out_txt << arr[i];
    Out_txt.close();
    fstream Out_bin("BINARY.txt", ios::binary | ios::out | ios::trunc);
    for (int i = 0; i < N; i++)
        Out_bin << arr[i];
    Out_bin.close();
    ofstream Out_num("NUM.txt", ios::out | ios::trunc);
    Out_num << N;
    Out_num.close();
    delete[] arr;
}