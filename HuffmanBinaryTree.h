#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include <iostream>
#include <vector>
#include "HuffmanCodeType.h"
using namespace std;

class BinaryTreeNode {
private:
    void preOrder(BinaryTreeNode *node);
    void inOrder(BinaryTreeNode *node);
    void postOrder(BinaryTreeNode *node);
    void printCodes(const BinaryTreeNode *node) const;
public:
    huffmanCodeType element;
    BinaryTreeNode *leftChild, *rightChild;
    bool operator()(BinaryTreeNode* l, BinaryTreeNode* r);
    BinaryTreeNode(){}
    BinaryTreeNode(huffmanCodeType elem);
    BinaryTreeNode* min();
    
    void preOrder();
    void inOrder();
    void postOrder();
    void printCode() const;
    ~BinaryTreeNode();
};

class huffmanBinaryTree{
private:
    BinaryTreeNode* addChild(huffmanCodeType element, BinaryTreeNode *node);
    BinaryTreeNode* removeChild(huffmanCodeType element, BinaryTreeNode *node);
    void setCode(struct BinaryTreeNode* root, string str);
public:
    BinaryTreeNode *root;
    huffmanBinaryTree(){ root = nullptr;}
    void addChild(huffmanCodeType element);
    void removeChild(huffmanCodeType element);
    void setCode();
    void print() const;
    void traverse() const;
    ~huffmanBinaryTree();
};

#endif /* BinaryTree_hpp */
