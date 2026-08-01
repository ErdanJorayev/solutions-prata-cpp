#pragma once

class Cd {
private:
    char* performers = nullptr;
    char* label = nullptr;
    int selections = 0;
    double playtime = 0.0;

protected:
    static char * cloneString(const char* str);

public:
    Cd();
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd& d);
    virtual ~Cd();

    virtual void Report() const;
    Cd& operator=(const Cd& d);
};

class Classic : public Cd {
private:
    char* artwork = nullptr;

public:
    Classic();
    Classic(const char* art, const char* per, const char* lab, int num, double pt);
    Classic(const Classic& cl);
    virtual ~Classic() override; 

    virtual void Report() const override;
    Classic& operator=(const Classic& cl);
};