#include "test_sort.hpp"
#include "heap_sort.hpp"
#include "i_task.hpp"

template<class T>
class SortTask: public ITask {
public:
    SortTask(int length) : length_(length) {
        data_ = new T[length_];
        for(int i=0; i<length_; i++)
            data_[i] = rand() % 100;
    }
    ~SortTask() {
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
    SortTask();
    T* data_;
    int length_;
};


TestSort::TestSort() {
    addTask(std::unique_ptr<ITask>(new SortTask<int>(300)));
}
