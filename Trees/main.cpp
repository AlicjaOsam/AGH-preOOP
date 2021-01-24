#include "MyDir.h"
#include <iostream>

int main()
{  
    std::cout << "*** Drzewo plikow ***" << std::endl;
        
    MyDir root;
    initDir(root, "root");
    printDir(root);
    std::cout << std::endl;
    addDir(root, "etc");
    MyDir* home = addDir(root, "home");
    addDir(*home, "rok1");
    MyDir* rok2 = addDir(*home, "rok2");
    addDir(*home, "rok3");
    addDir(*home, "");
    printDir(root);
    std::cout << std::endl;

    addDir(*home, "Absolwenci_IS");
    std::cout << std::endl;
        
    MyDir jan;
    initDir(jan, "Jan");
    addDir( *addDir(jan, "oceny"), "PPO");
    printDir(jan);
    std::cout << std::endl;

    addDir(*rok2, jan);

    printDir(*home);
    std::cout << std::endl;

    std::cout << "*** Czyszczenie ***" << std::endl;
    clearDir(&jan);
    printDir(root);
    clearDir(&root);
    delete home;
    delete rok2;
    
    return 0;
}