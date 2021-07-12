#include <stdio.h>
#include <iostream>
#include "HuffmanCodeType.h"
#include "HuffmanBinaryTree.h"
using namespace std;

bool BinaryTreeNode::operator()(BinaryTreeNode* l, BinaryTreeNode* r)
{
    return (l->element > r->element);
}

BinaryTreeNode::BinaryTreeNode(huffmanCodeType elem)
{
    leftChild = rightChild = NULL;
    this->element = elem;
}

BinaryTreeNode* BinaryTreeNode::min(){
    if (this->leftChild != nullptr){
        return leftChild->min();
    }
    return this;
}
void BinaryTreeNode::preOrder(){
    preOrder(this);
}

void BinaryTreeNode::inOrder(){
    inOrder(this);
}

void BinaryTreeNode::postOrder(){
    postOrder(this);
}

void BinaryTreeNode::printCode() const{
    printCodes(this);
}

void BinaryTreeNode::printCodes(const BinaryTreeNode *node) const{
    if (node != nullptr){
        printCodes(node->leftChild);
        if (node->element.getCh() != '$'){
            std::cout<<node->element.getCh()<<"("<<node->element.getCode()<<")"<<" ";
        }
        printCodes(node->rightChild);
    }
}

void BinaryTreeNode::preOrder(BinaryTreeNode *node){
    if (node != nullptr){
        if (node->element.getCh() != '$'){
            std::cout<<node->element.getCh()<<"("<<node->element.getFreq()<<")"<<" ";
        }else{
            std::cout<<"("<<node->element.getFreq()<<")"<<" ";
        }
        preOrder(node->leftChild);
        preOrder(node->rightChild);
    }
}

void BinaryTreeNode::inOrder(BinaryTreeNode *node){
    if (node != nullptr){
        inOrder(node->leftChild);
        if (node->element.getCh() != '$'){
            std::cout<<node->element.getCh()<<"("<<node->element.getFreq()<<")"<<" ";
        }else{
            std::cout<<"("<<node->element.getFreq()<<")"<<" ";
        }
        inOrder(node->rightChild);
    }
}

void BinaryTreeNode::postOrder(BinaryTreeNode *node){
    if (node != nullptr){
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        if (node->element.getCh() != '$'){
            std::cout<<node->element.getCh()<<"("<<node->element.getFreq()<<")"<<" ";
        }else{
            std::cout<<"("<<node->element.getFreq()<<")"<<" ";
        }
    }
}

BinaryTreeNode::~BinaryTreeNode(){
    delete leftChild;
    delete rightChild;
}

void huffmanBinaryTree::addChild(huffmanCodeType element){
    root = addChild(element, root);
}

BinaryTreeNode* huffmanBinaryTree::addChild(huffmanCodeType element, BinaryTreeNode *node){
    if (node == nullptr){
        node = new BinaryTreeNode;
        node->element = element;
        node->leftChild = nullptr;
        node->rightChild = nullptr;
    }else{
        if (node->element > element){
            node->leftChild = addChild(element, node->leftChild);
        }else{
            node->rightChild = addChild(element, node->rightChild);
        }
    }
    return node;
}

void huffmanBinaryTree::setCode(){
    setCode(root, "");
}

void huffmanBinaryTree::setCode(struct BinaryTreeNode* root, string str)
{
    if(!root){return;}
    if (root->element.getCh() != '$'){
        root->element.setCode(str);
    }
    setCode(root->leftChild, str + "0");
    setCode(root->rightChild, str + "1");
}


void huffmanBinaryTree::removeChild(huffmanCodeType element){
    root = removeChild(element, root);
}

BinaryTreeNode* huffmanBinaryTree::removeChild(huffmanCodeType element, BinaryTreeNode *node){
    if (node != nullptr){
        if (node->element == element){
            if (node->leftChild == nullptr && node->rightChild == nullptr){
                return nullptr;
            }
            if (node->leftChild == nullptr){
                return node->rightChild;
            }
            if (node->rightChild == nullptr){
                return node->leftChild;
            }
            node->element = node->rightChild->min()->element;
            node->rightChild = removeChild(node->element, node->rightChild);
        } else if (node->element > element){
            node->leftChild = removeChild(element, node->leftChild);
        }else{
            node->rightChild = removeChild(element, node->rightChild);
        }
    }
    return node;
}

void huffmanBinaryTree::print() const{
    root->printCode();
}


void huffmanBinaryTree::traverse() const{
    std::cout<<"Huffman tree preorder traversal:"<<endl;
    root->preOrder();
    std::cout<<"\nHuffman tree inorder traversal:"<<endl;
    root->inOrder();
    std::cout<<"\nHuffman tree postorder traversal:"<<endl;
    root->postOrder();
}

huffmanBinaryTree::~huffmanBinaryTree(){
    delete root;
}
