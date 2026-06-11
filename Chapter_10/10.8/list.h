
typedef unsigned int Item;

struct Node 
{   
    Item item;
    Node * ptr;
};

typedef Node * plist;

class List 
{
private:
    enum{MAX = 10};
    plist kek;
    unsigned int sz;
public:
    List();
    bool listempty() const;
    bool listfull() const;
    bool listpush(const Item & item);
    void visit(void (*pf)(Item & item));
};