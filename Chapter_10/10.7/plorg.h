
class plorg 
{
private:
    static const unsigned int S = 20; 
    char name[S];
    unsigned int CI;

public:
    plorg(const char * n = "plorga", unsigned int c = 50); 
    void indx(unsigned int c);
    void show() const;
}; 
