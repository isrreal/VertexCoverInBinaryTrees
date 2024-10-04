#ifndef NODE_HPP
#define NODE_HPP


#include <iostream>
#include <vector>
#include <random>
#include <utility>

struct Node {
    int key;
    int vertexCount;
    Node* left;
    Node* right;
    Node(int key = 0, Node* left = nullptr,
        Node* right = nullptr, int vertexCount = 0): key(key), left(left), right(right),
                                                    vertexCount(vertexCount) {}
};

#endif
