#include "BinarySearchTree.hpp"

int main() {

    std::pair<size_t, size_t> recursiveSolver = BinarySearchTree::getVertexCoverRecursive();
    std::pair<size_t, size_t> dynammicProgrammingSolver = BinarySearchTree::getVertexCoverDynammicProgramming();


	std::cout << "Size of the smallest vertex cover using recursion is " << recursiveSolver.first << std::endl;
    std::cout << "Amount of recursive calls: " << recursiveSolver.second << std::endl;

    std::cout << "\nSize of the smallest vertex cover using dynammic programming is " << dynammicProgrammingSolver.first << std::endl;
    std::cout << "Amount of recursive calls: " << dynammicProgrammingSolver.second << std::endl;

	return 0;
}