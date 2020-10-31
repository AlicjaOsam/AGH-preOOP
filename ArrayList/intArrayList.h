#ifndef _INTARRAYLIST_H_
#define _INTARRAYLIST_H_

class IntArrayList{

public:
    IntArrayList();
    IntArrayList(int );
    ~IntArrayList();
    void add(int );
    void add(int* , int );
    void add(int , int );
    void add(int , bool );
    void print();
    int find(int a);
    void printFind(int a);
    void remove(int a);
    void remove(int a, int b);
    
private:
    int _size;
    int _maxSize;
    int *_tab;
};

#endif 
