#include <iostream>
#include <string>
struct vipDefendGroup
{
    std::string name;
    double donation;
};

int main()
{
    size_t num = 0;
    size_t count = 0;

    std::cout << "Enter count patrons: ";
    (std::cin >> num).get();

    vipDefendGroup * arr = new vipDefendGroup[num];

    for (size_t i = 0; i < num; i++)
    {
        std::cout << "Enter name #" << i + 1 << " patron: ";
        getline(std::cin, arr[i].name);

        std::cout << "Enter donation: ";
        (std::cin >> arr[i].donation).get();
        if (arr[i].donation >= 10000)
            count++; 
    }


    if (count)
    {
        std::cout << "\nGrand Patrons:\n";
         for (size_t i = 0; i < num; i++)
             if (arr[i].donation >= 10000)
                 std::cout << arr[i].name << ' ' 
                           << arr[i].donation << '\n';
    }

    std::cout << "\nPatrons:\n";
    for (size_t i = 0; i < num; i++)
        if (arr[i].donation < 10000)
            std::cout << arr[i].name << ' ' 
                      << arr[i].donation << '\n';
        
    
    delete [] arr;
    
    return 0;
}