#include "test_manager.hpp"
#include "base/utility.hpp"
#include <iostream>

void TestManager::test() {
	{
		for (std::list<ITask*>::iterator iter = task_list_.begin(); iter != task_list_.end(); iter++)
		{
			auto start_time = Utility::getTime();
			(*iter)->run();
			auto end_time = Utility::getTime();
			std::cout <<std::endl<< (end_time - start_time) / 1000.0f << " seconds expend!" << std::endl;
		}
	}

}