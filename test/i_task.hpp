//
//  test_base.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#ifndef i_test_base_hpp
#define i_test_base_hpp

#include <stdio.h>

class ITask {
public:
    virtual void run() = 0;
    virtual ~ITask() = 0;
};

#endif /* i_test_base_hpp */
