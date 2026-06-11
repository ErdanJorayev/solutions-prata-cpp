#ifndef SALES_H_
#define SALES_H_

namespace SALES
{
    class Sales
    {
    private:
        static const unsigned int QUARTERS = 4;
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales(const double ar[], const unsigned int n);
        void setSales();
        void showSales() const;
    };
}

#endif
