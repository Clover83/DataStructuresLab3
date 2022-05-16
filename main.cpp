#include <iostream>
#include "OurNode.h"

int main() {

    OurNode::cValue = 0.5;
    OurNode* root = new OurNode(5);

    //root->left = new OurNode(3);
    //root->right = new OurNode(7);
    //root->right->right = new OurNode(8);
    //root->right->left = new OurNode(6);
    //root->left->right = new OurNode(4);
    //root->left->left = new OurNode(2);
    //root->left->left->left = new OurNode(1);
    //root->left->left->left->left = new OurNode(0);

    root->Insert(3);
    root->Insert(7);
    root->Insert(2);
    root->Insert(1);
    root->Insert(0);
    root->Insert(4);
    root->Insert(6);
    root->Insert(8);
    root->left->Balance();
    root->Print();

    delete root;

    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
