#include <iostream>
#include <time.h>
#include <iomanip>

int main(int argc, char const *argv[]) {
    clock_t start, end;
    start = clock();

    int numberList[1000];
    int length = sizeof(numberList)/sizeof(int);

    int index = 0;
    for (int i = length; i >= 0; i--) {
        numberList[index] = i;
        index++;
    }

    for (int i = 0; i < length; i++) {
        int carrier = numberList[i];

        /* If index pointing the 0-index continue to the next iteration */
        if (i == 0) {
            continue;
        }

        int index = i-1;
        while (index >= 0 && carrier <= numberList[index]) {
            numberList[index + 1] = numberList[index];
            numberList[index] = carrier;
            index--;
        }
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution time = " << std::fixed << time_taken << std::setprecision(9);
    std::cout << std::endl;


    return 0;
}
