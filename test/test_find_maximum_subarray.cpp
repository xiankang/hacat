//
//  test_find_maximum_subarray.cpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#include "test_find_maximum_subarray.hpp"



TestFindMaximumSubarray::TestFindMaximumSubarray() {
    std::cout<<"TestFindMaximumSubarray task"<<std::endl;
    for(int i=0; i < MAX; i++) {
        data_[i] = rand() % 100 - 50;
        std::cout << data_[i] << " ";
    }
    std::cout<<std::endl;
        
    addTask(std::unique_ptr<ITask>(new Task1<int>(data_, 0, MAX-1)));
    addTask(std::unique_ptr<ITask>(new Task2<int>(data_, 0, MAX-1)));
}

TestFindMaximumSubarray::~TestFindMaximumSubarray() {
}

