#ifndef HUFFMANCODETYPE_H
#define HUFFMANCODETYPE_H
#include <iostream>

class huffmanCodeType
{
    private: 
        char ch;
        int freq;
        std::string code;
    public:
        int operator %(int den) const {return (int) this->ch % den;}
        bool operator == (const huffmanCodeType & item) const {return (this->ch == item.ch);}
        bool operator != (const huffmanCodeType & item) const {return (this->ch != item.ch);}
        bool operator < (const huffmanCodeType & item) const {return (freq != item.freq ? freq < item.freq : ch < item.ch);}
        bool operator > (const huffmanCodeType & item) const {return (freq != item.freq ? freq > item.freq : ch > item.ch);}
        char getCh() const {return this->ch;}
        int getFreq() const{return this->freq;}
        std::string getCode() const{return this->code;}
        void setCh(char c){this->ch = c;}
        void setFreq(int f){this->freq = f;}
        void setCode(std::string c){this->code = c;}
        friend std::ostream &operator<<(std::ostream &output, const huffmanCodeType & item) {output << item.ch << " " << item.freq << " " << item.code << std::endl; return output;}
};

#endif