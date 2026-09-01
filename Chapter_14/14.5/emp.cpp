#include "emp.h"

// Realize abstr_emp
abstr_emp::abstr_emp()
    : fname("no name"), lname("no last name"),
      job("no job") {}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
                     const std::string & j) : fname(fn), lname(ln),
                                              job(j) {}

void abstr_emp::ShowAll() const
{
    std::cout << "Name: " << fname << '\n'
              << "Last name: " << lname << '\n'
              << "Job name: "  << job << '\n';
}

void abstr_emp::SetAll()
{
    std::cout << "Enter name: ";
    std::getline(std::cin, fname);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);

    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    e.ShowAll();
    return os;
}

abstr_emp::~abstr_emp() = default;


// Realize employee
employee::employee() = default;

employee::employee(const std::string & fn, const std::string & ln,
                   const std::string & j) 
                   : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const 
{
    abstr_emp::ShowAll();
}

void employee::SetAll() 
{
    abstr_emp::SetAll();
}

// Realize manager
manager::manager() = default;

manager::manager(const std::string & fn, const std::string & ln,
                 const std::string & j, int ico)
                 : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp & e, int ico) 
    : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m) = default;

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << inchargeof << '\n';
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter inchargeof: ";
    (std::cin >> inchargeof).get();
}

// Realize fink
fink::fink() : reportsto("no reportso") {}

fink::fink(const std::string & fn, const std::string & ln,
     const std::string & j, const std::string & rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const std::string & rpo)
    : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e) = default;

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reportso: " << reportsto << '\n';
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, reportsto);
}

// Realize highfink
highfink::highfink() = default;

highfink::highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
             fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
                  : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico)
    : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const std::string & rpo)
    : abstr_emp(m), manager(m), fink(m, rpo) {}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << InChargeOf() << '\n';
    std::cout << "Reportso: " << ReportsTo() << '\n';
}

void highfink::SetAll()
{
    abstr_emp::SetAll(); 
    
    std::cout << "Enter inchargeof: ";
    (std::cin >> InChargeOf()).get(); 
    
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, ReportsTo());
}