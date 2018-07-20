#pragma once

// 最大堆调整
template<class T>
void maxHeapify(T* data, int i, int size) {
    int left = (i<<1) + 1;
    int right = left + 1;

    int largest = i;
    if(left < size && data[left] > data[largest]) {
        largest = left;
    }
    
    if(right < size && data[right] > data[largest]) {
        largest = right;
    }
    
    if(largest != i) {
        T temp = data[i];
        data[i] = data[largest];
        data[largest] = temp;
        maxHeapify(data, largest, size);
    }
}

// 最小堆调整
template<class T>
void minHeapify(T* data, int i, int size) {
    int left = (i<<1) + 1;
    int right = left + 1;

    int min = i;
    if(left < size && data[left] < data[i]) {
        min = left;
    }
    
    if(right < size && data[right] < data[min]) {
        min = right;
    }
    
    if(min != i) {
        T temp = data[i];
        data[i] = data[min];
        data[min] = temp;
        minHeapify(data, min, size);
    }
}

template<class T>
void buildHeap(T* data, int size, bool isMaxHeap = true) {
    int last_parent = (size - 1) / 2;
    for(int i= last_parent; i>=0; i--) {
        if(isMaxHeap){
            maxHeapify(data, i, size);
        } else {
            minHeapify(data, i, size);
        }
    }
}

template<class T>
void heapSort(T* data, int size, bool order = true) {
    int size_ = size;
    if(order) {
        buildHeap(data, size, true);
        for(int i = size - 1; i >= 1; i--) {
            T temp = data[i];
            data[i] = data[0];
            data[0] = temp;
            size_--;
            maxHeapify(data, 0, size_);
        }
    } else {
        buildHeap(data, size, false);
        for(int i = size - 1; i >= 1; i--) {
            T temp = data[i];
            data[i] = data[0];
            data[0] = temp;
            
            minHeapify(data, 0, size_);
        }
    }
}
