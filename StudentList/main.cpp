#include "studList.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "*** Lista 1 ***" << std::endl;
    StudList list1;
    initList(&list1,"Lista1");
    char beata[] = "Beata";
    prepend(&list1, "Maria");
    prepend(&list1, beata);
    prepend(&list1, "Agnieszka");
    StudList* ptr1 = &list1;

    std::cout << ptr1->head->name << std::endl;
    std::cout << ptr1->head->next->name << std::endl;
    std::cout << ptr1->tail->name << std::endl;

    const StudList *ptrc=ptr1;  
    std::cout << "Czy " << ptrc->name << " jest pusta? " 
              << (isEmpty(ptrc)?"Tak":"Nie") << std::endl;
    print(ptrc);

    std::cout << "\n*** Lista 2 ***" << std::endl;
    StudList list2;
    char tomasz[]="Tomasz";
    initList(&list2,"Lista2");
    prepend(&list2, tomasz);
    prepend(&list2, "Krzysztof");
    prepend(&list2, "Adam");  
    print(&list2);

    std::cout << "\n*** Usuwanie ***" << std::endl;
    StudList* ptr2 = &list2;
    removeLast(ptr2);
    print(ptr2);
    std::cout << "--- Usuwam wszystkie elementy hurtem" << std::endl;
    clearList(&list1);
    std::cout << "Czy " << list1.name << " jest pusta? " 
              << (isEmpty(&list1)?"tak":"nie") << std::endl;
    std::cout << "--- Nazwa nadal istnieje, ale lista jest pusta" << std::endl;     
    print(&list1);
    prepend(&list1, tomasz);
    print(ptr1);
    removeLast(&list1);
    clearList(&list1);
    removeList(ptr1); 
  std::cout << "--- Usuwam listę element po elemencie" << std::endl;   
    print(&list2);
    removeLast(&list2);
    print(&list2);
    removeLast(&list2);
    print(&list2);
    removeLast(&list2);
    removeList(&list2);
}
