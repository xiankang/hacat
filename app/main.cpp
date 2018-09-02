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
#include "test_knapsack.hpp"
#include "test_manager.hpp"

using namespace std;
TestInstance(TestKnapsack)

int main(int argc, const char * argv[]){
	TestManager::instance()->test();

	system("pause");
    return 0;
}



