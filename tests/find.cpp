
//
// Created by pca05 on 30.09.16.
//

#include "../include/BinarySearchTree.h"
#include "catch.hpp"

SCENARIO("if element is in tree, find method must return it's pointer") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{1, 4, 5};
        WHEN("find") 
        {
            THEN("return pointer to element must not be nullptr") 
            {
                REQUIRE(*(tree.find(4)) == 4);
            }
        }
    }
}

SCENARIO("if element is not in tree, find method must return nullptr") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{1, 4, 5};
        WHEN("find") 
        {
            THEN("return pointer to element must be nullptr") 
            {
                REQUIRE(tree.find(2) == nullptr);
            }
        }
    }
}

SCENARIO("find method must work for constant tree and non-constant tree") 
{
    GIVEN("constant and non-constant tree") 
    {
        const BinarySearchTree<int> tree1{1, -2, 0};
        BinarySearchTree<int> tree2{1, 4, 5};
        WHEN("find") 
        {
            THEN("return element for constant and non-constant tree") 
            {
                REQUIRE(tree1.find(-2) && tree2.find(1));
            }
        }
    }
}
