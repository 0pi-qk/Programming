#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    system("chcp 65001");  //РЯ
    List list;
    complex* c;
    cout << "Текущий список состоит из пяти элементов:" << endl;
    c = new complex(1, -3);
    list.addElement(c);
    c = new complex(2, -2);
    list.addElement(c);
    c = new complex(3, -1);
    list.addElement(c);
    c = new complex(4, 0);
    list.addElement(c);
    c = new complex(5, 1);
    list.addElement(c);
    list.printstruct();
    cout << endl << "Добавим новый элемент списка:" << endl;
    c = new complex(6, 2);
    list.addElement(c);
    list.printstruct();
    cout << endl << "Удалим элемент списка:" << endl;
    list.deleteElement(c->GetNum() - 1);
    list.printstruct();
    cout << endl << "Добавим новый элемент списка в позицию 2:" << endl;
    c = new complex(7, 3);
    list.addElementAfter(c, 2);
    list.printstruct();
    cout << endl << "Удалим элемент списка с позиции 3:" << endl;
    list.deleteElement(3);
    list.printstruct();
    cout << endl << "Определим позицию комплексного числа 7+3i:" << endl;
    cout << list.find(list[2]);  //cout << list.find(c);
    return 0;
}


