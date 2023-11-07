#pragma once
#include "complex.h"

template <typename T>
class Element {
public:
    T content;
    Element<T>* next;
    Element<T>* addAfter(Element<T>* newElement);
    void deleteAfter();
    Element(T from);
    friend bool operator== (Element<T>& c1, T& c2);
    ~Element();
};

template <typename T>
class List {
private:
    Element<T>* base = NULL;
public:
    Element<T>* getLast();
    int getLength();
    Element<T>* addElement(T newElement);  //добавить элемент
    Element<T>* addElementAfter(T newElement, int index); // добавить по номеру
    void deleteElement(int index);//удалить/удалить по номеру
    Element<T>* get(int index);
    int find(T by);  //найти позицию по значению
    void printstruct();  //вывести структуру
    friend ostream& operator<<(ostream&, const Element<T>&);
    T& operator[](int index);

};

template <typename T>
Element<T>* List<T>::getLast()
{
    if (!base)
    {
        return base;
    }
    else
    {
        Element<T>* temp = base;
        while (temp->next != base)
            temp = temp->next;
        return temp;
    }
}

template <typename T>
int List<T>::getLength()
{
    if (!base)
        return 0;
    Element<T>* temp = base;
    int res = 0;
    do
    {
        res += 1;
        temp = temp->next;
    } while (temp != base);
    return res;
}

template <typename T>
Element<T>* List<T>::addElement(T newElemen)
{
    Element<T>* newElement = new Element<T>(newElemen);
    if (!base)
    {
        base = newElement;
        newElement->next = newElement;
    }
    else
    {
        getLast()->addAfter(newElement);
    }
    return newElement;
}

template <typename T>
Element<T>* List<T>::addElementAfter(T newElemen, int index)
{
    Element<T>* newElement = new Element<T>(newElemen);
    index -= 1;
    if (!base)
    {
        return NULL;
    }
    else
    {
        Element<T>* temp = base;
        for (int i = 0; i < index; i += 1)
        {
            temp = temp->next;
            if (temp == base)
                return NULL;
        }
        return temp->addAfter(newElement);
    }
}

template <typename T>
void List<T>::deleteElement(int index)
{
    if (index == 0)
    {
        index = getLength() - 1;
    }
    else
        index -= 1;

    Element<T>* temp = get(index);
    if (!temp)
    {
        cout << "index is out of bounds\n";
        return;
    }

    if (temp == temp->next)
    {
        delete base;
        base = NULL;
    }
    else
        temp->deleteAfter();
}

template <typename T>
Element<T>* List<T>::get(int index)
{
    if (!base)
    {
        return NULL;
    }
    else
    {
        Element<T>* temp = base;
        for (int i = 0; i < index; i += 1)
        {
            temp = temp->next;
            if (temp == base)
                return NULL;
        }
        return temp;
    }
}

template <typename T>
bool operator== (Element<T>& c1, T& c2)
{
    return (c1.content == c2);
}

template <typename T>
int List<T>::find(T by)
{
    if (!base)
        return -1;
    int res = 0;
    Element<T>* temp = base;
    while (!(by == temp->content))
    {
        temp = temp->next;
        res += 1;
        if (temp == base)
            return -1;
    }
    return res;
}

template <typename T>
ostream& operator<<(ostream& os, const Element<T>& c) {
    os << c.content;
    return os;
}

template <typename T>
void List<T>::printstruct()
{
    if (!base)
        cout << "no structures to print\n";
    else
    {
        Element<T>* temp = base;
        do
        {
            cout << *temp << "   ";
            temp = temp->next;
        } while (temp != base);
    }
}

template <typename T>
T& List<T>::operator[](int index)
{
    Element<T>* temp = get(index);
    if (!temp)
    {
        cout << "index is out of bounds\n";
        complex* t = NULL;
        return t;
    }
    return temp->content;
}

template <typename T>
Element<T>* Element<T>::addAfter(Element<T>* newElement)
{
    Element<T>* old = this->next;
    this->next = newElement;
    newElement->next = old;
    return newElement;
}

template <typename T>
void Element<T>::deleteAfter()
{
    Element<T>* temp = next;
    if (this == temp)
        return;
    this->next = this->next->next;
    delete temp;
}

template <typename T>
Element<T>::Element(T from)
{
    this->content = from;
    this->next = NULL;
}

template <typename T>
Element<T>::~Element()
{
}
