#pragma once
#include "test_base.hpp"
#include <vector>
#include "i_task.hpp"
#include "sort/heap_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/counting_sort.hpp"
#include "sort/radix_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/shell_sort.h"
#include "sort/bubble_sort.h"
#include "sort/bucket_sort.h"
#include "sort/merge_sort.hpp"
#include "sort/selection_sort.h"

template<class T>
void print(T* data, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << data[i] << " ";

	std::cout << std::endl;
}

template<class T>
class HeapSortTask : public ITask {
public:
	HeapSortTask(int length) : length_(length) {
		data_ = new T[length_];
		for (int i = 0; i < length_; i++)
			data_[i] = rand() % 100;
	}
	~HeapSortTask() {
		delete data_;
		data_ = nullptr;
	}

	void run() {
		std::cout << "data" << std::endl;
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}
		std::cout << std::endl << "build max heap" << std::endl;
		buildHeap(data_, length_);
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}

		std::cout << std::endl << "sort by heap sort" << std::endl;
		heapSort(data_, length_);
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}
	}
private:
	HeapSortTask();
	T* data_;
	int length_;
};

template<class T>
class QuickSortTask : public ITask {
public:
	QuickSortTask(int length) : length_(length) {
		data_ = new T[length_];
		for (int i = 0; i < length_; i++)
			data_[i] = rand() % 100;
	}
	~QuickSortTask() {
		delete data_;
		data_ = nullptr;
	}

	void run() {
		std::cout << "data" << std::endl;
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}

		std::cout << std::endl << "sort by quick sort" << std::endl;
		quickSort(data_, 0, length_ - 1);
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}
	}
private:
	QuickSortTask();
	T* data_;
	int length_;
};

template<class T>
class CountingSortTask : public ITask {
public:
	CountingSortTask(int length) : length_(length) {
		data_ = new T[length_];
		for (int i = 0; i < length_; i++)
			data_[i] = rand() % 100;
	}
	~CountingSortTask() {
		delete data_;
		data_ = nullptr;
	}

	void run() {
		std::cout << "data" << std::endl;
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}

		std::cout << std::endl << "sort by counting sort" << std::endl;
		countingSort(data_, length_, 100);
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}
	}
private:
	CountingSortTask();
	T* data_;
	int length_;
};

template<class T>
class RadixSortTask : public ITask {
public:
	RadixSortTask(int length) : length_(length) {
		data_ = new T[length_];
		for (int i = 0; i < length_; i++)
			data_[i] = rand() % 100;
	}
	~RadixSortTask() {
		delete data_;
		data_ = nullptr;
	}

	void run() {
		std::cout << "data" << std::endl;
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}

		std::cout << std::endl << "sort by radix sort" << std::endl;
		radixSort(data_, length_, 2);
		for (int i = 0; i < length_; i++) {
			std::cout << data_[i] << " ";
		}
	}
private:
	RadixSortTask();
	T* data_;
	int length_;
};




class ShellSortTask : public ITask
{
	void run()
	{
		std::vector<int> data;
		for (int i = 0; i < 100; ++i)
			data.push_back(rand() % 100);
		print<int>(data.data(), data.size());

		std::cout << "sort by shell sort" << std::endl;

		shell_sort(data.data(), data.size());

		print(data.data(), data.size());

	}
};

class TestSort: public TestBase {
public:
    TestSort();
};