#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Node.hpp"

class BinarySearchTree {
private:
    Node* root;
    static BinarySearchTree* binarySearchTree;

    BinarySearchTree();

    Node* insert(Node* node, int value);
    
    void insert(int value);

    // Returns the value of vertex cover, and the amount of recursion calls, respectively.
    std::pair<size_t, size_t> vertexCoverRecursive(Node* node);

    // Returns the value of vertex cover, and the amount of recursion calls, respectively.
    std::pair<size_t, size_t> vertexCoverDynammicProgramming(Node* node);

public:
    static size_t i;
    static size_t j;
    static std::pair<size_t, size_t> getVertexCoverRecursive();
    static std::pair<size_t, size_t> getVertexCoverDynammicProgramming();
};


#endif