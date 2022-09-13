//
//  main.cpp
//  Ex 5, Q4
//  The following program (https://www.doc.ic.ac.uk/~wjk/C++Intro/RobMillerEx5-4.cpp) prints out a table of shop closing times. It uses a named enumeration to define a new data type "Day", and a function "closing_time(...)" to generate the closing time from a given day (not a complicated function - the shop closes at 5pm every day).
//  Modify it to answer these (https://www.doc.ic.ac.uk/~wjk/C++Intro/RobMillerE5.html) questions
// 
//  Modified by Max Mitchell on 13/09/2022.
//

#include <iostream>
using namespace std;
    
enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
    
int closing_time(Day day_of_the_week);
void print_day(Day day_of_the_week, ostream& stream);


int main()
{
    int count;

    cout.setf(ios::left);
    /* Print table heading */
    cout.width(17);
    cout << "DAY";
    cout << "CLOSING TIME\n\n";

    /* Print table from Sunday to Saturday */
    for (count = static_cast<int>(Sun) ; count <= static_cast<int>(Sat) ; count++)
    {
        cout.width(19);
 
        print_day(static_cast<Day>(count), cout);
        cout << closing_time(static_cast<Day>(count)) << "pm\n";
    }

    return 0;
}


/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
int closing_time(Day day_of_the_week)
{
    switch (day_of_the_week) // NB: could also be done with 'else if's
    {
        case Sun: return 1;
        case Sat: return 5;
        case Wed: return 8;
        default: return 6; // TODO: Change default to handle errors and change switch accordingly 
    }
}

void print_day(Day day_of_the_week, ostream& stream){
    switch (day_of_the_week)
    {
        case Sun: cout << "Sunday"; break;
        case Mon: cout << "Monday"; break;
        case Tue: cout << "Tuesday"; break;
        case Wed: cout << "Wednesday"; break;
        case Thu: cout << "Thursday"; break;
        case Fri: cout << "Friday"; break;
        case Sat: cout << "Saturday"; break;
        default:  cout << "ERROR!";
    }
}
