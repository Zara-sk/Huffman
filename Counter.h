#ifndef HUFFMAN_COUNTER_H
#define HUFFMAN_COUNTER_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Counter
{
private:

    class Element
    {
    public:

        int number;
        T name;

        explicit Element(T name): number(0), name(name){};

        Element& operator++();
        Element& operator--();
        Element operator++(int);
        Element operator--(int);

        friend class Counter;
    };

    int size;
    vector<Element> array;

    static bool comparator(Element el1, Element el2);

public:

    Counter(): size(0){};
    ~Counter() = default;

    void sort();

    template <typename T1> Counter::Element& operator[](T1 index);
    template <typename T2> friend ostream& operator<<(ostream &out, Counter<T2> &counter);

};


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


#include "CounterRealization.h"

#endif //HUFFMAN_COUNTER_H
