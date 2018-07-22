#include "test_sort.hpp"
#include "heap_sort.hpp"
#include "i_task.hpp"
#include "quick_sort.hpp"

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

TestSort::TestSort() {
    addTask(std::unique_ptr<ITask>(new HeapSortTask<int>(300)));
    addTask(std::unique_ptr<ITask>(new QuickSortTask<int>(300)));
}
