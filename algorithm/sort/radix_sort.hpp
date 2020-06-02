//
//  radix Sort
//  test
//  基数排序
//  Created by MacBook Pro on 2018/6/2.
//

#pragma once
#include "counting_sort.hpp"

//基数排序
void radixSort(int* data, int length, int d) {
    for(int i=1; i<=d; i++) {
        countingSortForRadix(data, length, i);
    }
}
