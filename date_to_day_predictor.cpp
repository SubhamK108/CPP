#include <iostream>
using namespace std;
#include <map>
#include <string>


int no_leap_year(int n)
{ return (n / 4); }

int no_od_day(int n)
{ return (n % 7); }

int closest_century(int y)
{
    int cy = 400;
    while (cy < y)
    { cy += 400; }
    cy -= 400;
    return (cy);
}

bool is_leap_year(int y)
{
    if (y % 100 != 0 && y % 4 == 0)
    { return (true); }
    else if (y % 100 == 0 && y % 400 == 0)
    { return (true); }
    else
    { return (false); }
}


int main()
{
    map <int, string> od_day;
    map <int, int> month_od_day, century_od_day;

    od_day = {
        {0, "Sunday"},
        {1, "Monday"},
        {2, "Tuesday"},
        {3, "Wednesday"},
        {4, "Thursday"},
        {5, "Friday"},
        {6, "Saturday"}
    };

    month_od_day = {
        {1, 3},
        {2, 0},
        {3, 3},
        {4, 2},
        {5, 3},
        {6, 2},
        {7, 3},
        {8, 3},
        {9, 2},
        {10, 3},
        {11, 2},
        {12, 3}
    };

    century_od_day = {
        {100, 5},
        {200, 3},
        {300, 1},
        {400, 0}
    };


    int n[3], d, m, y, y2, cy, a, b, b2, sum;
    string day;
    cout << "Enter the Date (DD.MM.YYYY): ";
    cin >> n[0];
    for (int i = 1; i < 3; i++)
    {
        cin.ignore(256, '.');
        cin >> n[i];
    }
    d = n[0]; m = n[1]; y = n[2];

    y2 = y - 1;
    cy = closest_century(y);
    a = y2 - cy;
    if (a < 100)
    {
        b = a;
        a = 0;
    }
    else
    {
        b = a % 100;
        a -= b;
        a = century_od_day.at(a);
    }
    b2 = no_leap_year(b);
    b -= b2;
    b2 *= 2;
    sum = a + b + b2;
    for (int i = 1; i < m; i++)
    { sum += month_od_day.at(i); }
    sum += no_od_day(d);
    if (m > 2 && is_leap_year(y))
    { sum += 1; }
    sum = no_od_day(sum);

    day.append(od_day.at(sum));
    cout << "It's a " << day << endl;
}