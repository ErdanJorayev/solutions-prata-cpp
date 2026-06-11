#include <iostream>
#include <new>
#include "list.h"

List::List()
{
    kek = nullptr;
    sz = 0;
}

bool List::listempty() const
{
    return sz == 0;
}

bool List::listfull() const
{
    return sz >= MAX;
}

bool List::listpush(const Item & item)
{
    if (listfull())
    {
        return false;
    }

    Node* new_node = new (std::nothrow) Node;
    if (new_node == nullptr)
    {
        return false;
    }

    new_node->item = item;
    new_node->ptr = kek;
    kek = new_node;
    sz++;
    return true;
}

void List::visit(void (*pf)(Item & item))
{
    Node* current = kek;
    while (current != nullptr)
    {
        pf(current->item);
        current = current->ptr;
    }
}
