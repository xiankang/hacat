//
//  test_base.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#ifndef test_base_hpp
#define test_base_hpp

#include <stdio.h>

#include "i_task.hpp"
#include "test_manager.hpp"
#include <iostream>

#define EnableTest(TestClass)\
private:\
static TestClass instance;\
public:\
	TestClass() {\
		TestManager::instance()->addTask(this);\
	}\
	~TestClass() {\
		TestManager::instance()->removeTask(this);\
	}

#define TestInstance(TestClass)\
TestClass TestClass##instance;


class TestBase : public ITask{

public:
    TestBase() {
        TestManager::instance()->addTask(this);
    }
    
    virtual ~TestBase() {
        TestManager::instance()->removeTask(this);
    }
    
	virtual void run(){}
};



#endif /* test_base_hpp */
