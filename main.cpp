#include <iostream>
#include "Counter.h"
#include <string>

using namespace std;

int main() {
    Counter<char> a;
    a['F'];
    a['F']++;
    a['D'];
    cout << a;
}
