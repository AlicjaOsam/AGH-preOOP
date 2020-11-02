/* 
  * destruktor usuwający wszystkie elementy listy i kontrolnie wywołujący isEmpty()
  * addSorted - wstawia wartość w porządku rosnącym
  * removeValue - usuwa pierwszy znaleziony element o wartości value
*/

#include "intLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    IntLinkedList list1;
    cout << "size: " << list1.size() << endl;
    cout << (list1.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list1.print();
    list1.removeLast();
    cout << "   --- test prepend 3,5,-2,8,7,0 ---" << endl;
    list1.prepend(3);
    list1.prepend(5);
    list1.prepend(-2);
    list1.prepend(8);
    list1.prepend(7);
    list1.prepend(0);
    list1.print();
    cout << "size: " << list1.size() << endl;
    cout << (list1.contains(-5) ? "-5: Element znaleziony" : "-5: Element nieznaleziony")<< endl;
    list1.prepend(-5);
    list1.print();
    cout << (list1.contains(-5) ? "-5: Element znaleziony" : "-5: Element nieznaleziony")<< endl;
    cout << (list1.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;

    cout << "   --- test remove last 0,5,-2,-5 ---" << endl;
    list1.removeLast();
    list1.print();
    list1.removeValue(0);
    list1.removeValue(5);
    list1.removeValue(-2);
    list1.removeValue(-5);
    list1.print();
    cout << "size: " << list1.size() << endl;

    cout << "   --- test SortedList ---" << endl;
    IntLinkedList list2;
    cout << "size: " << list2.size() << endl;
    cout << (list2.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list2.print();
    list2.addSorted(3);
    list2.addSorted(1);
    list2.addSorted(-1);
    list2.addSorted(4);
    list2.print();
    list2.removeLast();
    list2.print();
    cout << "size: " << list2.size() << endl;
    return 0;
}

/* Oczekiwany wynik: ./main
size: 0
Lista pusta
[]
   --- test prepend 3,5,-2,8,7,0 ---
[0, 7, 8, -2, 5, 3]
size: 6
-5: Element nieznaleziony
[-5, 0, 7, 8, -2, 5, 3]
-5: Element znaleziony
Lista nie jest pusta
   --- test remove last 0,5,-2,-5 ---
[-5, 0, 7, 8, -2, 5]
[7, 8]
size: 2
   --- test SortedList ---
size: 0
Lista pusta
[]
[-1, 1, 3, 4]
[-1, 1, 3]
size: 3
Destruktor: Lista pusta
Destruktor: Lista pusta
*/
