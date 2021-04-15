#ifndef HUFFMAN_COUNTER_H
#define HUFFMAN_COUNTER_H

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

template<typename T>
class Counter
{
private:

    class Element
    {
    private:
    public:

        int number;
        T name;

        explicit Element(T name): number(0), name(name){};
        friend class Counter;
    };

    int size;
    vector<Element> array;

public:

    Counter();
    ~Counter() = default;

    template <typename T1> Counter::Element& operator[](T1 index);
    template <typename T2> friend ostream& operator<<(ostream &out, Counter<T2> &counter);

};


#include "CounterRealization.h"

#endif //HUFFMAN_COUNTER_H
