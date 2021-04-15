#ifndef HUFFMAN_COUNTERREALIZATION_H
#define HUFFMAN_COUNTERREALIZATION_H

#include "Counter.h"

template<typename T>
Counter<T>::Counter()
{
    size = 0;
}


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
    for (auto &e: counter.array)
        out << '[' << e.name << ", " << e.number << "] ";

    return out;
}


#endif //HUFFMAN_COUNTERREALIZATION_H
