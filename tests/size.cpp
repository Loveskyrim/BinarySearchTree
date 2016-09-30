/
// Created by pca05 on 30.09.16.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../include/BinarySearchTree.h"
#include "catch.hpp"


SCENARIO("empty tree size must be equal 0") {
    GIVEN("empty tree") {
        BinarySearchTree<int> tree;
        WHEN("tatrgeted size") { 
            THEN("size must be equal 0") { 
                REQUIRE(tree.size() == 0);
                 }
             }
        }
}


SCENARIO("size of non-empty tree must not be equal 0") {
    GIVEN("non-empty tree") {
        BinarySearchTree<int> tree{1, 3, 5};
        WHEN("decide size") {
            THEN("size must not be equal 0") {
                REQUIRE(tree.size() != 0);
                 }
             }
      }
}


SCENARIO("size of constant tree must be equal to size of non-constant tree") {
    GIVEN("constant and non-constant trees")
    {
    const BinarySearchTree<int> tree1{1, 3, 5, 0};
    BinarySearchTree<int> tree2{1, 3, 5, -1};
    WHEN("compare sizes") {
        THEN("sizes must be equal") {
            REQUIRE(tree1.size() == tree2.size());
            }
          }
      }
}
