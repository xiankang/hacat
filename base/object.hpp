//
//  object.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/4.
//

#ifndef object_hpp
#define object_hpp

#include <stdio.h>
#include <string>

class Object{
public:
    Object(){}
    virtual std::string toString(){
        return "";
    }
    virtual ~Object() {}
};
#endif /* object_hpp */
