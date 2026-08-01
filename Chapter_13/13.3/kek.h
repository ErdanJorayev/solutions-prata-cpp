#pragma once
#include <iostream> 

class Abstract
{
private:
    char * label = nullptr;
    int rating = 0;
protected:
    char * cloneString(const char * str); 
public:
    Abstract() = default;
    Abstract(const char * lb, int rg);
    Abstract(const Abstract & a);
    virtual ~Abstract() = 0;

    Abstract & operator=(const Abstract & a);
    virtual void View() const;
};

class baseDMA : public Abstract
{
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA() override = default;
    baseDMA & operator=(const baseDMA & rs);
    virtual void View() const override;
};

class lacksDMA : public Abstract
{
private:
    static constexpr int COL_LEN = 40;
    char color[COL_LEN];
public:
    lacksDMA(const char * a = "blank", const char * l = "null",
            int r = 0);
    lacksDMA(const lacksDMA & rs);
    virtual ~lacksDMA() override = default;
    lacksDMA & operator=(const lacksDMA & rs);
    virtual void View() const override;
};

class hasDMA : public Abstract
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
            int r = 0);
    hasDMA(const hasDMA & hs);
    virtual ~hasDMA() override;
    hasDMA & operator=(const hasDMA & rs);
    virtual void View() const override;
};
