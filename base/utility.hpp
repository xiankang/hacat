//
//  utility.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/5.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
class Utility {
public:
    static float getTime() {
        auto tp = std::chrono::steady_clock::now();
        std::time_t cur_time = std::chrono::duration_cast<std::chrono::nanoseconds>(tp.time_since_epoch()).count();
        return (float)cur_time / 1000000;
    }
};
#endif /* utility_hpp */
