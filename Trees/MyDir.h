#include <iostream>
#pragma once

/**
*struktura obrazująca drzewo katalogów w systemie
*@tparam parent wskaźnik do rodzica
*@tparam children tablica wskaźników do potomków
*@tparam number liczba potomków
*@tparam name nazwa węzła
*/
struct MyDir{
  MyDir *parent;
  MyDir *children[10];
  int number;
  std::string name;
};

/**
*funkcja inicjująca węzeł
*@param mydir referencja do nowego drzewa
*@param name nazwa węzła
*/
void initDir(MyDir& mydir, const std::string name);

/**
*funkcja wypisująca drzewo
*@param mydir referencja do drzewa
*@param deep głębokość drzewa
*/
void printDir(MyDir& mydir, int deep = 0);

/**
*funkcja dodająca węzeł do drzewa
*@param mydir referencja do drzewa
*@param name nazwa węzła
*/
MyDir* addDir(MyDir& mydir, const std::string name);

/**
*funkcja dodająca całą gałąź do drzewa
*@param mydir1 referencja do drzewa
*@param mydir2 referencja do gałęzi drzewa
*/
MyDir* addDir(MyDir& mydir1, MyDir& mydir2);

/**
*funkcja usuwająca węzeł
*@param mydir referencja do drzewa
*/
void clearDir(MyDir* mydir);