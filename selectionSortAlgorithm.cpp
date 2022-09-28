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

    /* Perform selection sort */
    for (int i = 0; i < length; i++) {
        int minimum = i;
        for (int j = i;j < length; j++) {
            if (numberList[j] <= numberList[minimum]) {
                minimum = j;
            }
            if (j == length - 1) {
                int carry = numberList[i];
                numberList[i] = numberList[minimum];
                numberList[minimum] = carry;
            }
        }
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution time = " << std::fixed << time_taken << std::setprecision(9);
    std::cout << std::endl;

    return 0;
}
