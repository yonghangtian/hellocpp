#include <iostream>
#include "stonewt.h"

const unsigned int ARR_SIZE = 6;

int main()
{

    unsigned int counter = 0;

    Stonewt stArray[ARR_SIZE] = {Stonewt(5), Stonewt(10), Stonewt(12)};
    Stonewt test(11);
    Stonewt smallestElement = stArray[0], largestElement = stArray[0];

    for (int i = 3; i < ARR_SIZE; i++) {
        double input;
        std::cout << "Enter a value #" << i + 1 << ": ";
        std::cin >> input;
        std::cin.get();
        stArray[i] = Stonewt(input);
    }

    for (const Stonewt & i : stArray) {
        if (i >= test)
        counter++;

        if (i > largestElement)
        largestElement = i;
        if (i < smallestElement)
        smallestElement = i;
    }
    std::cout << std::endl << "Smallest element: " << smallestElement;
    std::cout << std::endl << "Largest element: " << largestElement;
    std::cout << std::endl << "Number of elements >= 11: " << counter << std::endl;

    return 0;

}