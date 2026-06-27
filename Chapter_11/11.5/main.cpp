#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    using std::endl;

    Stonewt s1(2, 7.5);
    Stonewt s2(25.6);
    Stonewt result;

    cout << "Initial objects:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "\nTesting modes for s2:" << endl;
    s2.set_int_lbs_mode();
    cout << "Integer pounds: " << s2 << endl;
    s2.set_stone_mode();
    cout << "Stone mode:     " << s2 << endl;
    s2.set_float_lbs_mode();
    cout << "Float pounds:   " << s2 << endl;

    cout << "\nTesting math operators:" << endl;
    result = s1 + s2;
    cout << "s1 + s2 = " << result << endl;

    result = s2 - s1;
    cout << "s2 - s1 = " << result << endl;

    result = s1 * 2.5;
    cout << "s1 * 2.5 = " << result << endl;

    result = 2.0 * s2;
    cout << "2.0 * s2 = " << result << endl;

    cout << "\nTesting implicit conversion (basic type + class):" << endl;
    result = s1 + 14.5;
    cout << "s1 + 14.5 = " << result << endl;

    return 0;
}