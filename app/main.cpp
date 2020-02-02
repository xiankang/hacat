//
//  main.cpp
//  test
//
//  Created by MacBook Pro on 2018/6/1.
//

#include "test_manager.hpp"
#include "test_red_black_tree.h"

int main(int argc, const char * argv[]){
	RegisterTest(test_red_black_tree)

	TestManager::instance()->test();

	system("pause");
    return 0;
}



