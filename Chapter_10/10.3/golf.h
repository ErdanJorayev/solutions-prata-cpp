#ifndef GOLF_H_
#define GOLF_H_

class Golf 
{
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap_value;

public:
    Golf();
    Golf(const char* name, int hc);
    int setgolf();
    void handicap(int hc);
    void showgolf() const;
};

#endif
