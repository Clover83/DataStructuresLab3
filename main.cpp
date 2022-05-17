#include <iostream>
#include "Tests.h"

int main() {

    OurNode::cValue = 0.90;
    Tests::Test1(10000, 1000, 10);

    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
