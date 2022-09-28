#include <iostream>
#include <time.h>
#include <iomanip>

int main(int argc, char const *argv[]) {
    clock_t start, end;
    start = clock();

    /* Field to declare the array */
    int numberList[1000];
    int length = sizeof(numberList)/sizeof(int);

    int index = 0;
    for (int i = length; i >= 0; i--) {
        numberList[index] = i;
        index++;
    }

    /* Perform bubble sort */
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length; j++) {
            if (numberList[j] < numberList[j-1]) {
                int carry = numberList[j-1];
                numberList[j-1] = numberList[j];
                numberList[j] = carry;
            }
        }
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution time = " << std::fixed << time_taken << std::setprecision(9);
    std::cout << std::endl;

    return 0;
}
