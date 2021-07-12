#include "HuffmanCodes.h"
#include "HuffmanBinaryTree.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "fstream"
#include <list>

huffmanCodes::huffmanCodes(){
    size = 0;
    symbols = new huffmanCodeType[0];
    tree = huffmanBinaryTree();
}

void huffmanCodes::sort(huffmanCodeType arr[]){
    for(int i = 0; i < size-1; i++){
        int lowest = i;
        for(int j = i + 1; j < size; j++){
            if (arr[lowest] > arr[j]){
                lowest = j;
            }
        }
        if(lowest != i){
            huffmanCodeType temp = arr[lowest];
            arr[lowest] = arr[i];
            arr[i] = temp;
        }
    }
}

bool huffmanCodes::readFile(const std::string & fileName){
    std::ifstream input(fileName);
    if(input.is_open()){
        string str = "";
        int count = 0;
        std::getline(input, str);
        size = stoi(str);
        symbols = new huffmanCodeType[size];
        while(std::getline(input, str))
        {
            string val = "";
            for(int i = 0;i<str.length();i++){
                if(i == 0){
                    symbols[count].setCh(str[i]);
                }else if(i >= 2){
                    val += str[i];
                }
            }
            symbols[count].setFreq(stoi(val));
            count += 1;
        }
        input.close();
        return true;
    }
    return false;
}


bool compares(BinaryTreeNode* l, BinaryTreeNode* r)
{
    return (l->element > r->element);
}

void huffmanCodes::generateCodes(){
    
    BinaryTreeNode *left, *right, *parent;
    tree = huffmanBinaryTree();
    list<BinaryTreeNode*> List;
    
    for (int i = 0; i < size; ++i){
        List.push_back(new BinaryTreeNode(symbols[i]));
    }
    
    List.sort(compares);
    
    while (List.size() != 1) {
        huffmanCodeType elem;

        left = List.back();
        List.pop_back();

        right = List.back();
        List.pop_back();

        elem.setCh('$');
        elem.setFreq(left->element.getFreq() + right->element.getFreq());
        parent = new BinaryTreeNode(elem);

        parent->leftChild = left;
        parent->rightChild = right;
          
        List.push_front(parent);
        List.sort(compares);
    }
    
    tree.root = List.front();
    tree.setCode();
    tree.traverse();
}

void huffmanCodes::printCodes() const{
    tree.print();
}

void huffmanCodes::sortSymbolsByFreq(){
    sort(symbols);
}

void huffmanCodes::printFreq() const{
    for(int i = 0 ; i < size ; i++){
        std::cout<<symbols[i].getCh()<<"("<<symbols[i].getFreq()<<")"<<" ";
    }
}

huffmanCodes::~huffmanCodes(){
    delete [] symbols;
}
