#ifndef HUFFMAN_COUNTER_H
#define HUFFMAN_COUNTER_H

#include <vector>
#include <utility>

using namespace std;

template<typename T>
class Counter
{
private:
    vector<pair<T, int>> array;
    int size;

public:
    Counter();
    ~Counter();

};

#include "CounterRealization.h"

#endif //HUFFMAN_COUNTER_H
