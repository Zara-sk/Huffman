#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
    Counter<char> a;
    a['F']; a['O']; a['A']; a['D'];
    a['F']++;
    a['A']++; a['A']++; a['A']++; a['A']++; a['A']++;
    a['O']++; a['O']++; a['O']++;
    a['D']++; a['D']++; a['D']++; a['D']++; a['D']++; a['D']++;
    a.sort();
    cout << a;
}
