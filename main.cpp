#include <iostream>
#include "Tests.h"

int main() {

    OurNode::cValue = 0.51;
    Tests::Test2(1500, 10);
    
    
    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
