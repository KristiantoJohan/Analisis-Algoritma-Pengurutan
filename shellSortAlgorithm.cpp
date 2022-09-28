#include <iostream>
#include <time.h>
#include <iomanip>

int main(int argc, char const *argv[]) {
    clock_t start, end;
    start = clock();

    int numberList[100000];
    int length = sizeof(numberList)/sizeof(int);

    int index = 0;
    for (int i = length; i >= 0; i--) {
        numberList[index] = i;
        index++;
    }

    for (int interval = length/2; interval > 0; interval /= 2) {
        for (int i = interval; i < length; i++) {
            int temporary = numberList[i];
            int j;
            for (j = i; j >= interval && numberList[j - interval] > temporary; j -= interval) {
                numberList[j] = numberList[j - interval];
            }
            numberList[j] = temporary;
        }
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Execution time = " << std::fixed << time_taken << std::setprecision(9);
    std::cout << std::endl;

    
    return 0;
}
