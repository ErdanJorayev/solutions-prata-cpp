#include <iostream>

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    std::cout << "Enter class size: ";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout << "Done\n";
    return 0;
}
int getinfo(student pa[], int n)
{
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "Student #" << i + 1 << '\n';
        std::cout << "Enter the fullname: ";
        std::cin.getline(pa[i].fullname, SLEN);
        
        if (pa[i].fullname[0] == '\0')
            break;
            
        std::cout << "Enter the hobby: ";
        std::cin.getline(pa[i].hobby, SLEN);

        std::cout << "Enter the ooplevel: ";
        (std::cin >> pa[i].ooplevel).get(); 
        
        count++;
    }
    return count;
}

void display1(student st)
{
    std::cout << "Name: "      << st.fullname << '\n'
              << "Hobby: "     << st.hobby    << '\n'
              << "OOP level: " << st.ooplevel << '\n';
}

void display2(const student * ps)
{
    std::cout << "Name: "      << ps->fullname << '\n'
              << "Hobby: "     << ps->hobby    << '\n'
              << "OOP level: " << ps->ooplevel << '\n';
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << "Name: "      << pa[i].fullname << '\n'
                  << "Hobby: "     << pa[i].hobby    << '\n'
                  << "OOP level: " << pa[i].ooplevel << '\n';
}














