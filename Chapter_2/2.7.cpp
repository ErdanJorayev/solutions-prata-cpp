#include <iostream>

using namespace std;

// Функция только выводит данные, ничего не возвращая
void displayTime(int hours, int minutes) {
    cout << "Time: " << hours << ":" << minutes << endl;
}

int main() {
    int hours = 0;
    int minutes = 0;

    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    displayTime(hours, minutes);

    return 0;
}
