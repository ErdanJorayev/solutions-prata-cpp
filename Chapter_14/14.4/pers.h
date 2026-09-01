#include <string>
#include <iostream>
#include <cstdlib>

class Person
{
private:
    std::string name;
    std::string surname;
public:
    Person() : name("no name"), surname("no surname") {}
    Person(const std::string & n, const std::string & s)    
        : name(n), surname(s) {}
    virtual ~Person() = default; 
    virtual void Show() const 
    {
        std::cout << "Name: " << name << '\n';
        std::cout << "Surname: " << surname << '\n';
    }
};

class Gunslinger : virtual public Person
{
private:
    int misfire;
public:
    Gunslinger() : misfire(0) {}
    Gunslinger(const std::string & nm, const std::string & sm, int mf) 
        : Person(nm, sm), misfire(mf) {}
    double Draw() const { return 34.4; }
    void Show() const override
    {
        Person::Show();
        std::cout << "Misfire: " << misfire << '\n'; 
    }
};

class PokerPlayer : virtual public Person
{
public: 
    PokerPlayer() = default;
    PokerPlayer(const std::string & nm, const std::string & sm) 
        : Person(nm, sm) {}
    
    int Draw() const { return std::rand() % 52 + 1; } 
    
    void Show() const override
    {
        Person::Show();
    }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() = default;

    BadDude(const std::string & nm, const std::string & sm, int mf)
        : Person(nm, sm), Gunslinger(nm, sm, mf), PokerPlayer(nm, sm) {}

    double Gdraw() const { return Gunslinger::Draw(); }
    int Cdraw() const { return PokerPlayer::Draw(); } 
    void Show() const override
    {
        Gunslinger::Show(); 
        std::cout << "Next Card: " << Cdraw() << '\n';
    }
};