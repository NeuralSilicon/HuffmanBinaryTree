#ifndef HUFFMANCODES_H
#define HUFFMANCODES_H

#include "HuffmanCodeType.h"
#include "HuffmanBinaryTree.h"

class huffmanCodes
{
private:
    huffmanCodeType *symbols;
    int size;
    huffmanBinaryTree tree;
    void sort(huffmanCodeType []);
public:
    huffmanCodes();
    bool readFile(const std::string &);
    void generateCodes();
    void printCodes() const;
    void sortSymbolsByFreq();
    void printFreq() const;
    ~huffmanCodes();
};

#endif
