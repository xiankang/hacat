//
//  utility.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/5.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <chrono>

class Utility {
public:
    static float getTime() {
        auto tp = std::chrono::steady_clock::now();
        float cur_time = std::chrono::duration_cast<std::chrono::nanoseconds>(tp.time_since_epoch()).count() / 1000000.0f;
        return cur_time;
    }
};
#endif /* utility_hpp */
