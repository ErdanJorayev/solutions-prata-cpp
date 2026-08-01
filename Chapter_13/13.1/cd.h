class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    // Added const to parameters to accept string literals
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd(); // Virtual destructor ensures proper cleanup in polymorphic deletion

    virtual void Report() const; // Displays all data
    Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char artwork[20];  // Stores music name / artwork description
public:
    // Added const to parameters to accept string literals
    Classic(const char * art, const char * per, const char * lab, int num, double pt);
    // Added const to allow copying from temporary (rvalue) and const objects
    Classic(const Classic & cl);
    Classic();
    ~Classic(); // Automatically virtual since the base class destructor is virtual

    virtual void Report() const; // Overrides base method to display all data including artwork
    Classic & operator=(const Classic & cl);
};
