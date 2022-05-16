#include <iostream>
#include "OurNode.h"
#include "OurTree.h"

int main() {

    //root->left = new OurNode(3);
    //root->right = new OurNode(7);
    //root->right->right = new OurNode(8);
    //root->right->left = new OurNode(6);
    //root->left->right = new OurNode(4);
    //root->left->left = new OurNode(2);
    //root->left->left->left = new OurNode(1);
    //root->left->left->left->left = new OurNode(0);

    OurNode::cValue = 0.9;
    OurTree tree;
    /*tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(0);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);*/

    for (int i = 0; i < 20; i++) {
        tree.Insert(i);
    }
    //root->left->Balance();
    tree.Print();

    // Prevent console from shutting
    int n;
    std::cin >> n;
    return 0;
}
