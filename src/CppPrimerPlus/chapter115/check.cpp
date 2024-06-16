#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    using std::endl;

    Stonewt aida(3, 12.1);
    Stonewt tosca(60.6);
    Stonewt temp;

    cout << "Aida and Tosca:\n";
    cout << aida<<"; " << tosca << endl;
    temp = aida + tosca;     // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida* 1.17;  // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    cout << "Tosca * 10.0 : " << tosca * 10.0<< endl;

}