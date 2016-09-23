#include "../include/BinarySearchTree.h"

int main()
{
    BinarySearchTree<char> TreeOne{'a', 'b', 'c', 'd', 'e'};
    std::cout << TreeOne << std::endl;

    BinarySearchTree<double> TreeTwo {1.1, 2.2, 3.3, 4.4};
    std::cout << TreeTwo << std::endl;
    return 0;
};
