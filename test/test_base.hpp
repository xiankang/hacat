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
#include "i_task.hpp"
#include <list>
#include "base/utility.hpp"
#include <iomanip>
#include <memory>

class TestBase{
private:
    std::list<std::unique_ptr<ITask>> task_list_;
public:
    TestBase() {
    }
    
    virtual ~TestBase() {
    }
    virtual void addTask(std::unique_ptr<ITask> task){
        task_list_.push_back(move(task));
    }
    
    virtual void test() {
        for(std::list<std::unique_ptr<ITask>>::iterator iter = task_list_.begin(); iter!= task_list_.end(); iter++)
        {
            auto start_time = Utility::getTime();
            (*iter)->run();
            auto end_time = Utility::getTime();
            std::cout<<(end_time - start_time)/1000.0f<<" seconds expend!"<<std::endl;
        }
    }
};
#endif /* test_base_hpp */
