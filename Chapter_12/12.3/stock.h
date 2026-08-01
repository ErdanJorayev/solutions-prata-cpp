#ifndef STOCK00_H_
#define STOCK00_H_

#include <iostream>

class Stock
{
private:
    char * company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val; }

public:
    Stock();
    Stock(const char * str, long n = 0, double pr = 0.0);
    ~Stock();
    
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);

    const char * co_name() const {return company;}
    long co_shares() const {return shares;}
    double co_shval() const {return share_val;}
    double co_tlval() const {return total_val;}


    const Stock & topval(const Stock & s) const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
};

#endif