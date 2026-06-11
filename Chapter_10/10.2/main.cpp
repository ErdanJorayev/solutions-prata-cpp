#include "person.h"
#include <iostream>

int main()
{
    Person erdan("Jorayev", "Erdan");
    Person alex("Mercer");

    erdan.Show();
    erdan.FormalShow();

    alex.FormalShow();

    return 0;
}