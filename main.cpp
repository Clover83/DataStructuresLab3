#include <iostream>
#include "Tests.h"

int main() {

    OurNode::cValue = 0.51;
    Tests::Test3(1000, 10, 10);

    
    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
