#include "chapter3.h"

int convertMeterAndInch()
{
    float highInMeter, highInInch;

    cout << "Please input your hight in meter:" << endl;
    cin >> highInMeter;

    highInInch = highInMeter * meterToInch;

    cout << "Your hight in inch is: " << highInInch << endl;
    
    return 1;
}


