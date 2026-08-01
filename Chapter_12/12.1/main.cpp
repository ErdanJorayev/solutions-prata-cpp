#include <iostream>
#include "cow.h"

int main()
{
    Cow test1;
    Cow test2("Moo1", "Devoloper", 23);
    Cow test3 = test2;
    Cow test4;
    test4 = test2;
    test1 = test4;
    
    test1.ShowCow();
    test2.ShowCow();
    test3.ShowCow();
    test4.ShowCow();

    return 0;
}