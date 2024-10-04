#include "BinarySearchTree.hpp"

    BinarySearchTree::BinarySearchTree() {
        std::random_device randomNumber;
        std::mt19937 seed(randomNumber());
        std::uniform_int_distribution<int> gap(-100, 100);
        std::uniform_int_distribution<int> instanceSize(1, 3000);
        int tamanho = instanceSize(seed);
        for (size_t i = 0; i < tamanho; ++i)
            this->insert(gap(seed));
    }

    Node* BinarySearchTree::insert(Node* node, int value) {
        if (!node)
            return new Node(value);
        else if (node->key < value)
            node->right = insert(node->right, value);
        else 
            node->left = insert(node->left, value);
        return node;
    }
    
    void BinarySearchTree::insert(int value) { this->root = insert(this->root, value); }

    // Returns the value of vertex cover, and the amount of recursion calls, respectively.
    std::pair<size_t, size_t> BinarySearchTree::vertexCoverRecursive(Node* node) {
        ++BinarySearchTree::i;
        if (!node)
            return {0, BinarySearchTree::i};
        if (!node->left && !node->right)
            return {0, BinarySearchTree::i};    

        int sizeIncludingRoot = 1 + vertexCoverRecursive(node->left).first + vertexCoverRecursive(node->right).first;
    
        int sizeExcludingRoot = 0;
        if (node->left)
            sizeExcludingRoot += 1 + vertexCoverRecursive(node->left->left).first + vertexCoverRecursive(node->left->right).first;
        if (node->right)
            sizeExcludingRoot += 1 + vertexCoverRecursive(node->right->left).first + vertexCoverRecursive(node->right->right).first; 
        
        return {sizeIncludingRoot < sizeExcludingRoot ? sizeIncludingRoot : sizeExcludingRoot, BinarySearchTree::i};
    }

    // Returns the value of vertex cover, and the amount of recursion calls, respectively.
    std::pair<size_t, size_t> BinarySearchTree::vertexCoverDynammicProgramming(Node* node) {
        ++BinarySearchTree::j;
        if (!node)
            return {0, BinarySearchTree::j};
        if (!node->left && !node->right)
            return {0, BinarySearchTree::j};   
        if (node->vertexCount != 0)
            return {node->vertexCount, BinarySearchTree::j};
        
        int sizeIncludingRoot = 1 + vertexCoverDynammicProgramming(node->left).first +
            vertexCoverDynammicProgramming(node->right).first;
    
        int sizeExcludingRoot = 0;

        if (node->left)
            sizeExcludingRoot += 1 + vertexCoverDynammicProgramming(node->left->left).first +
                vertexCoverDynammicProgramming(node->left->right).first;
        if (node->right)
            sizeExcludingRoot += 1 + vertexCoverDynammicProgramming(node->right->left).first +
                vertexCoverDynammicProgramming(node->right->right).first; 

        node->vertexCount = sizeIncludingRoot < sizeExcludingRoot ? sizeIncludingRoot : sizeExcludingRoot;
        return {node->vertexCount, BinarySearchTree::j};
    }

    // static methods definition

    std::pair<size_t, size_t> BinarySearchTree::getVertexCoverRecursive() {
        return BinarySearchTree::binarySearchTree->vertexCoverRecursive(BinarySearchTree::binarySearchTree->root); 
    }

    std::pair<size_t, size_t> BinarySearchTree::getVertexCoverDynammicProgramming() {
        return BinarySearchTree::binarySearchTree->vertexCoverDynammicProgramming(BinarySearchTree::binarySearchTree->root); 
    }

    // static variables

    BinarySearchTree* BinarySearchTree::binarySearchTree = new BinarySearchTree();
    size_t BinarySearchTree::i = 0;
    size_t BinarySearchTree::j = 0;
