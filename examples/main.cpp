    #include "../include/BinarySearchTree.h"

    int main()
    {
        BinarySearchTree<double> tree {1.1, 2.2, 3.3, 4.4, 4.0, 4.5};
        std::cout << tree << std::endl;
        tree.insert(-5.8);
        std::cout << tree << std::endl;

        if (tree.remove(4.4))
            std::cout << tree << std::endl;

        return 0;
    };
