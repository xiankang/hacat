#include "test_sort.hpp"
#include "sort/heap_sort.hpp"
#include "i_task.hpp"
#include "sort/quick_sort.hpp"
#include "sort/counting_sort.hpp"
#include "sort/radix_sort.hpp"

template<class T>
class HeapSortTask: public ITask {
public:
    HeapSortTask(int length) : length_(length) {
        data_ = new T[length_];
        for(int i=0; i<length_; i++)
            data_[i] = rand() % 100;
    }
    ~HeapSortTask() {
        delete data_;
        data_ = nullptr;
    }

    void run() {
        std::cout<<"data"<<std::endl;
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
        std::cout<<std::endl<<"build max heap"<<std::endl;
        buildHeap(data_, length_);
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
        
        std::cout<<std::endl<<"sort by heap sort"<<std::endl;
        heapSort(data_, length_);
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
    }
private:
    HeapSortTask();
    T* data_;
    int length_;
};

template<class T>
class QuickSortTask: public ITask {
public:
    QuickSortTask(int length) : length_(length) {
        data_ = new T[length_];
        for(int i=0; i<length_; i++)
            data_[i] = rand() % 100;
    }
    ~QuickSortTask() {
        delete data_;
        data_ = nullptr;
    }

    void run() {
        std::cout<<"data"<<std::endl;
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
        
        std::cout<<std::endl<<"sort by quick sort"<<std::endl;
        quickSort(data_, 0, length_-1);
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
    }
private:
    QuickSortTask();
    T* data_;
    int length_;
};

template<class T>
class CountingSortTask: public ITask {
public:
    CountingSortTask(int length) : length_(length) {
        data_ = new T[length_];
        for(int i=0; i<length_; i++)
            data_[i] = rand() % 100;
    }
    ~CountingSortTask() {
        delete data_;
        data_ = nullptr;
    }
    
    void run() {
        std::cout<<"data"<<std::endl;
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
        
        std::cout<<std::endl<<"sort by counting sort"<<std::endl;
        countingSort(data_, length_, 100);
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
    }
private:
    CountingSortTask();
    T* data_;
    int length_;
};

template<class T>
class RadixSortTask: public ITask {
public:
    RadixSortTask(int length) : length_(length) {
        data_ = new T[length_];
        for(int i=0; i<length_; i++)
            data_[i] = rand() % 100;
    }
    ~RadixSortTask() {
        delete data_;
        data_ = nullptr;
    }
    
    void run() {
        std::cout<<"data"<<std::endl;
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
        
        std::cout<<std::endl<<"sort by radix sort"<<std::endl;
        radixSort(data_, length_, 2);
        for(int i=0; i<length_; i++){
            std::cout<< data_[i] <<" ";
        }
    }
private:
    RadixSortTask();
    T* data_;
    int length_;
};

TestSort::TestSort() {
}
