#pragma once
#include "counting_sort.hpp"

void radixSort(int* data, int length, int d) {
    for(int i=1; i<=d; i++) {
        countingSortForRadix(data, length, i);
    }
}
