//
//  main.cpp
//  test
//
//  Created by MacBook Pro on 2018/6/1.
//

#include <iostream>
#include <stdlib.h>
#include "test_base.hpp"
#include "test_find_maximum_subarray.hpp"
#include "test_matrix.hpp"
#include "test_sort.hpp"

using namespace std;

void runTest(TestBase& t) {
    t.test();
}

int main(int argc, const char * argv[]){
//    TestFindMaximumSubarray test_find_maximum_subarray;
//    runTest(test_find_maximum_subarray);
    // TestMatrix test_matrix;
    TestSort test_sort;
    runTest(test_sort);
    return 0;
}



