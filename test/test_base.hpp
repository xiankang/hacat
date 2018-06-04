//
//  test_base.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#ifndef test_base_hpp
#define test_base_hpp

#include <stdio.h>
#include <ctime>
#include <iostream>
#include "task_base.hpp"
#include <list>

class TestBase{
private:
    std::list<TaskBase*> task_list_;
public:
    TestBase() {
    }
    
    ~TestBase() {
        clearTask();
    }
    virtual void addTask(TaskBase* task){
        task_list_.push_back(task);
    }
    
    virtual void clearTask(){
        for(std::list<TaskBase*>::iterator iter = task_list_.begin(); iter!= task_list_.end(); iter++)
        {
            task_list_.erase(iter++);
            delete *iter;
        }
    }
    virtual void test() {
        for(std::list<TaskBase*>::iterator iter = task_list_.begin(); iter!= task_list_.end(); iter++)
        {
            std::time_t start_time = std::clock();
            (*iter)->run();
            std::time_t end_time = std::clock();
            std::cout<<float(end_time - start_time)/1000<<" seconds expend!"<<std::endl;
        }
    }
};
#endif /* test_base_hpp */
