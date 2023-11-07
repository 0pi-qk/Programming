#pragma once
#include "complex.h"

class List {
public:
    class Element {
    public:
        complex* content;
        Element* next;
        Element* addAfter(Element* newElement);
        void deleteAfter();
        Element(complex* from);
        ~Element();
    };
private:
    Element* base = NULL;
public:
    Element* getLast();
    int getLength();
    Element* addElement(complex* newElement);  //добавить элемент
    Element* addElementAfter(complex* newElement, int index); // добавить по номеру
    void deleteElement(int index);//удалить/удалить по номеру
    Element* get(int index);
    int find(complex* by);  //найти позицию по значению
    void printstruct();  //вывести структуру
    friend ostream& operator<<(ostream&, const Element&);
    complex*& operator[](int index);
};

