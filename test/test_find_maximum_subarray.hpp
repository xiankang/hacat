//
//  test_find_maximum_subarray.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#ifndef test_find_maximum_subarray_hpp
#define test_find_maximum_subarray_hpp

#include <stdio.h>
#include "test_base.hpp"
#include "task_base.hpp"
#include "../algorithm/divide_conquer/find_maximum_subarray.hpp"
#include <iostream>

const static int MAX = 100000;

template <class T>
class Task1:public TaskBase{
    T* data_;
    int start_;
    int end_;
public:
    Task1(T* data, int start, int end) {
        data_ = data;
        start_ = start;
        end_ = end;
    }
    virtual void run(){
        SubarrayResult<int> result = findMaximumSubarray(data_, start_, end_);
        std::cout<<"result"<<std::endl;
        std::cout<<result.toString()<<std::endl;
    }
};

template <class T>
class Task2:public TaskBase{
    T* data_;
    int start_;
    int end_;
public:
    Task2(T* data, int start, int end) {
        data_ = data;
        start_ = start;
        end_ = end;
    }
    virtual void run(){
        SubarrayResult<int> result = findMaximumSubarray2(data_, start_, end_);
        std::cout<<"result2"<<std::endl;
        std::cout<<result.toString()<<std::endl;
    }
};

class TestFindMaximumSubarray : public TestBase{
private:
    int data_[MAX];
public:
    TestFindMaximumSubarray();
    ~TestFindMaximumSubarray();
};
#endif /* test_find_maximum_subarray_hpp */
