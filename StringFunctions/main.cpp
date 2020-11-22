#include "studList.h"
#include "mystr.h"
#include <iostream>

int main() {

    StudList list1, list2;
    initList(&list1,"Lista1");
    initList(&list2,"Lista2");
    StudList *ptr1 = &list1;

    std::cout << "*** Napis 1 ***" << std::endl; 
    char *text1 = mycopy("Agnieszka,Monika Maria;;;Gosia");
    std::cout << "Napis \"" << text1 << "\" ma dlugosc " << mystrlen(text1) << std::endl;
    char znak=',';
    std::cout << "Znak '" << znak << "' " << (findSep(znak,text1)?"znaleziony" :"nie znaleziony") << std::endl;

    
    MyString tosplit1;
    initMyString(&tosplit1, text1, ",;."); 
    for (int i=1; i<4; ++i){
      std::cout <<"Do podzielenia: "<< tosplit1.next << std::endl;
      std::cout << "Pobrano: " << mystrtok(&tosplit1)<< std::endl;
    }

    std::cout << "\n*** Napis 2 ***" << std::endl;
    char *ola = mycopy("Ola");
    char* dwa = mystrcat (ola, "Piotr  Janusz");
    std::cout << dwa << std::endl;
    char *text2 = mystrcat (dwa, "Basia,Anna-Maria",';'); 
    std::cout << "Napis \"" << text2 << "\" ma dlugosc " << mystrlen(text2) << std::endl;
   
    MyString tosplit2;
    initMyString(&tosplit2,text2); 
    addSep(&tosplit2, " ,;\t");  
    std::cout <<"Do podzielenia: "<< tosplit2.begin << std::endl;
    split2list(ptr1, &tosplit2);
    print(ptr1);
        
    std::cout << "\n*** Napis 3 ***" << std::endl;  
    MyString tosplit3;
    initMyString(&tosplit3,"...A,B;-C--D E-F .G\tH,"," ,;.-\t");
    split2list(&list2, &tosplit3);
    print(&list2);

    std::cout << "\n*** Czyszczenie ***" << std::endl;
    removeFirst(&list2);
    print(&list2);
    clearList(ptr1);
    removeList(&list1);
    removeList(&list2);
    delete[] text1;
    delete[] ola;
    delete[] dwa;
    delete[] text2;
    removeMyString(&tosplit1);
    removeMyString(&tosplit2);
    removeMyString(&tosplit3);
}