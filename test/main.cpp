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

using namespace std;

//template<class T>
//void run(T) {
//    TestBase* pTest = new T();
//    pTest->run();
//    delete pTest;
//}

int main(int argc, const char * argv[]){
//    TestBase* pTest = new TestFindMaximumSubarray();
    TestBase* pTest = new TestMatrix();
    pTest->test();
    delete pTest;
    return 0;
}



