#include <iostream>
#include "HuffmanCodes.h"

int main(int argc, const char * argv[]) {
    
    huffmanCodes codes1;
    if(codes1.readFile("input.txt"))
    {
        std::cout << "Original frequencies: " << std::endl;
        codes1.printFreq();
        std::cout << std::endl << "Sorted frequencies: " << std::endl;
        codes1.sortSymbolsByFreq();
        codes1.printFreq();
        std::cout << std::endl << "Generate Huffman tree: " << std::endl;
        codes1.generateCodes();
        std::cout << std::endl << "Huffman codes: " << std:: endl;
        codes1.printCodes();
    }
    
    return 0;
}
