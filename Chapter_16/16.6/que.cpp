#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

// Класс данных
class Customer
{
private:
    long arrive;      // момент появление клиента
    int processtime;  // время обслуживание клиента
public:
    Customer() { arrive = processtime = 0; }  // конструктор по умолчанию
    void set(long when);                      // функция установки значения
    long when() const { return arrive; }      // возврат arrive
    int ptime() const { return processtime; } // возврат proccestime 
};

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

// Переименовали
typedef Customer Item;

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main()
{
    // Объявили данные чтобы удобно было использовать
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // Это чтобы при каждом запуске программы были разные значения
    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    unsigned long int qs;
    cin >> qs;    
    std::queue<Item> line; 
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;  // Установка времени в часах для симуляции

    long cyclelimit = MIN_PER_HR * hours; // эмуляция будет запускать 1 цикл в минуту
    cout << "Enter the average number of customers per hour: "; // количество клиентов в час
    double perhour;
    cin >> perhour; // ввели среднее количество клиентов час
    double min_per_cust; // среднее время между появлением клиентов
    min_per_cust = MIN_PER_HR / perhour; 
    Item temp;          // новый клиент
    long turnaways = 0; // не допущенные клиенты в очередь
    long customers = 0; // допущенные клиенты в очередь
    long served = 0;    // обслуженные клиенты в очереди
    long sum_line = 0;  // общая длина очереди
    int wait_time = 0;  // время до освобождение банкомата
    long line_wait = 0; // общее время в очереди

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))    // есть подошедший клиент
        {  
            if (line.size() == qs)           // очередь полна 
                turnaways++;
            else
            {
                customers++;             // клиент допущен
                temp.set(cycle);         // 
                line.push(temp);      // клиент вышел из очереди
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
           Item current = line.front();         // 1. Достали клиента из головы очереди
           line.pop();                          // 2. Удалили его из очереди
     
           wait_time = current.ptime();         // 3. Берем ЕГО время обслуживания
           line_wait += cycle - current.when(); // 4. Считаем ЕГО время ожидания
           served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "average wait time: " << (double) line_wait / served
                                      << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}