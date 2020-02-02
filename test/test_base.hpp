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

#include <iostream>

class TestBase : public ITask{

public:
    TestBase() {

    }
    
    virtual ~TestBase() {

    }
    
	virtual void run(){}
};



#endif /* test_base_hpp */
