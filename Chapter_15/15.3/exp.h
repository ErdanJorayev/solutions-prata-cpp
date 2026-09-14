#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean() = default;
    bad_hmean(double a = 0, double b = 0) 
        : logic_error::logic_error("hmean() invalid arguments: "), v1(a), v2(b) {}
    
    const char * what() const noexcept
    {
        std::cout << logic_error::what();
        std::cout << v1 << " == " << "-" << v2 << '\n';
        return "ERROR";
    }
};


class bad_gmean : public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean() = default;
    bad_gmean(double a = 0, double b = 0) : 
    logic_error::logic_error("gmean() arguments: "), v1(a), v2(b) {}

    const char * what() const noexcept
    {
        std::cout << logic_error::what();
        std::cout << v1 << " < 0" << " and " << v2 << " < 0\n";
        return "\nERROR\n";
    }
};

