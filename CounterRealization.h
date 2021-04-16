#ifndef HUFFMAN_COUNTERREALIZATION_H
#define HUFFMAN_COUNTERREALIZATION_H

#include "Counter.h"


template<typename T>
bool Counter<T>::comparator(Element el1, Element el2) {return el1.number < el2.number;}


template<typename T>
void Counter<T>::sort() {std::sort(this->array.begin(), this->array.end(), comparator);}

template<typename T>
template<typename T1>
typename Counter<T>::Element& Counter<T>::operator[](T1 index)
{
    // Если подобный элемент уже содержится, находим, возвращаем
    for (auto &e: array)
        if (e.name == index)
            return e;

    // В противном случае создаем, возвращаем
    auto e = new Element(index);
    array.push_back(*e);
    size++;
    return *e;
}

template<typename T>
std::ostream& operator<< (std::ostream &out, Counter<T> &counter)
{
    out << "[ ";
    for (auto &e: counter.array)
        out << '(' << e.name << ", " << e.number << ") ";
    out << "]";
    return out;
}

template<typename T>
typename Counter<T>::Element& Counter<T>::Element::operator++()
{
    number++;
    return *this;
}

template<typename T>
typename Counter<T>::Element& Counter<T>::Element::operator--()
{
    number--;
    return *this;
}

template<typename T>
typename Counter<T>::Element Counter<T>::Element::operator++(int)
{
    Element temp(this->name);
    temp.number = this->number;
    ++(*this);
    return temp;
}

template<typename T>
typename Counter<T>::Element Counter<T>::Element::operator--(int)
{
    Element temp(this->name);
    temp.number = this->number;
    --(*this);
    return temp;
}
#endif //HUFFMAN_COUNTERREALIZATION_H
