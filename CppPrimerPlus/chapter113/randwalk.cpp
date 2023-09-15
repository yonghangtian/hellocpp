// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"

template <typename T>
T maxn(T * arr, int size);

template <typename T>
T avgn(T * arr, int size);

template <typename T>
T minn(T * arr, int size);

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int trials;
    cout << "Enter the number of trials (q to quit): ";
    while (cin >> trials)
    {   
        if(trials <= 0){
            break;
        }
        int records[trials];
        cout << "Enter target distance (q to quit): ";
        if (!(cin >> target))
            break;
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Number of trials: " << trials << ", Target Distance: " << target << ", Step Size: " << dstep << endl; 

        for (int i = 0; i < trials; i ++) 
        {
            while (result.magval() < target)
            {
                // cout << steps << ": " << result << endl;
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL); 
                result = result + step;
                steps++;
            }
            // store steps into an array.
            records[i] = steps;
            // cout << "After " << steps << " steps, the subject "
            //     "has the following location:\n";
            // cout << result << endl;
            // result.polar_mode();
            // cout << " or\n" << result << endl;
            // cout << "Average outward distance per step = "
            //     << result.magval()/steps << endl;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        
        // report statistics
        for (int i = 0; i < trials; i++) {
            cout << records[i] << " ";
        }
        cout << endl;
        cout << "the max step is: " << maxn(records, trials) 
            << ", the avg step is: " << avgn(records, trials) 
            << ", the min step is: "<< minn(records, trials) << endl;

        records[trials] = {0};
        cout << "Enter the number of trials (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0; 
}


template <typename T>
T maxn(T * arr, int size)
{   
    T max = arr[0];

    for (int i = 1; i < size; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

template <typename T>
T avgn(T * arr, int size)
{   
    T sum = arr[0];

    for (int i = 1; i < size; i++) {
        sum += arr[i];
    }
    T avg = sum/size;
    return avg;
}

template <typename T>
T minn(T * arr, int size)
{   
    T min = arr[0];

    for (int i = 1; i < size; i++) {
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}
