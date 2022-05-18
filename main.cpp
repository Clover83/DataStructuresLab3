#include <iostream>
#include "Tests.h"

int main() {

    OurNode::cValue = 0.90;
    Tests::Test4(1500, 15, 5);
    
    
    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
