#pragma once
#include "base/singleton.hpp"
#include <list>
#include "i_task.hpp"

#define TestInstance(TestClass)\
static TestClass TestClass##instance;

#define RegisterTest(TestClass)\
TestInstance(TestClass)\
TestManager::instance()->addTask(&(TestClass##instance));

class TestManager : public Singleton<TestManager> {
private:
	std::list<ITask*> task_list_;

public:
	TestManager()
	{

	}
	void addTask(ITask* task) {
		task_list_.push_back(task);
	}
	void removeTask(ITask* task) {
		task_list_.remove(task);
	}

	virtual void test();
};