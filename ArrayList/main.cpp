#include <iostream>
#include "intArrayList.h"

int main() {
    IntArrayList list1(10), list2;
    std::cout << "************* LIST1 *************\n";
    std::cout << "------- ADD 7,-2,37 -------\n";
    list1.add(7);
    list1.add(-2);
    list1.add(37);
    list1.print(); 
    int tab[]={3,6,9};
    std::cout << "------- ADD [3,6,9] -------\n";
    list1.add(tab,3);
    list1.add(tab,3);
    list1.add(tab,3);
    list1.print(); 
    list1.printFind(37);
    std::cout << "------- REMOVE 37 -------\n";
    list1.remove(37);
    list1.print(); 
	  list1.printFind(37);
    std::cout << "------- ADD -50 IND=2 -------\n";
    list1.add(2,-50);
    list1.print(); 
    std::cout << "------- REMOVE -50 n=3 -------\n";
    list1.remove(-50,3);
    list1.print(); 
    std::cout << "------- ADD [3,6,9] -------\n";
    list1.add(tab,3);
    list1.print();
    std::cout << "\n************* LIST2 *************\n";
    std::cout << "------- ADD SORT -2,-4,10,5 -------\n";
    list2.add(-2);
    list2.add(-4, true);
    list2.add(10,true);
    list2.add(5,true);
    list2.print();
    std::cout << "------- ADD SORT 7,0,3,2 -------\n";
    list2.add(7,true);
    list2.add(0,true);
    list2.add(3,true);
    list2.add(2,true);
    list2.print();
    std::cout << "------- ADD SORT -8,6,13 -------\n";
    list2.add(-8,true);
    list2.add(6,true);
    list2.add(13,true);
    list2.print();
    return 0;
}

