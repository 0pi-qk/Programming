#include "list.h"
#include "Exception.h"

List::Element* List::getLast()
{
    if (!base)
    {
        return base;
    }
    else
    {
        Element* temp = base;
        while (temp->next != base)
            temp = temp->next;
        return temp;
    }
}

int List::getLength()
{
    if (!base)
        return 0;
    Element* temp = base;
    int res = 0;
    do
    {
        res += 1;
        temp = temp->next;
    } while (temp != base);
    return res;
}

List::Element* List::addElement(complex* newElemen)
{
    Element* newElement = new Element(newElemen);
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

List::Element* List::addElementAfter(complex* newElemen, int index)
{
    Element* newElement = new Element(newElemen);
    index -= 1;
    if ((index < 0) || (index > getLength() - 1))
        throw indexoutofbounds("Выход за пределы списка");
    if (!base)
    {
        return NULL;
    }
    else
    {
        Element* temp = base;
        for (int i = 0; i < index; i += 1)
        {
            temp = temp->next;
            if (temp == base)
                return NULL;
        }
        return temp->addAfter(newElement);
    }
}

void List::deleteElement(int index)
{
    if (index == 0)
    {
        index = getLength() - 1;
    }
    else
        index -= 1;
    Element* temp = get(index);
    if (!temp)
    {
        throw indexoutofbounds("Выход за пределы списка");
    }

    if (temp == temp->next)
    {
        delete base;
        base = NULL;
    }
    else
        temp->deleteAfter();
}

List::Element* List::get(int index)
{
    if (!base)
    {
        return NULL;
    }
    else
    {
        Element* temp = base;
        for (int i = 0; i < index; i += 1)
        {
            temp = temp->next;
            if (temp == base)
                return NULL;
        }
        return temp;
    }
}


int List::find(complex* by)
{
    if (!base)
        return -1;
    int res = 0;
    Element* temp = base;
    while (temp->content != by)
    {
        temp = temp->next;
        res += 1;
        if (temp == base)
            return -1;
    }
    return res;
}

void List::printstruct()
{
    if (!base)
        throw nostructure("Структура пуста");
    else
    {
        Element* temp = base;
        do
        {
            cout << *temp << "   ";
            temp = temp->next;
        } while (temp != base);
    }
}

ostream& operator<<(ostream& os, const List::Element& c) {
    os << c.content->get_com();
    return os;
}

complex*& List::operator[](int index)
{
    Element* temp = get(index);
    if (!temp)
    {
        cout << "index is out of bounds\n";
        complex* t = NULL;
        return t;
    }
    return temp->content;
}

List::Element* List::Element::addAfter(Element* newElement)
{
    Element* old = this->next;
    this->next = newElement;
    newElement->next = old;
    return newElement;
}

void List::Element::deleteAfter()
{
    Element* temp = next;
    if (this == temp)
        return;
    this->next = this->next->next;
    delete temp;
}

List::Element::Element(complex* from)
{
    this->content = from;
    this->next = NULL;
}

List::Element::~Element()
{
    delete content;
}
