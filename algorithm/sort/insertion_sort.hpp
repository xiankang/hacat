//
//  InsertionSort.hpp
//  hacat
//  插入排序
//  先选数据，在比较的时候，会移动数据，然后空出合适的位置给所选数据
//  Created by MacBook Pro on 2018/6/1.
//

#ifndef insertion_sort_hpp
#define insertion_sort_hpp

#include <stdio.h>

template<class T>
void insertionSort(T * data, int begin, int end, int delta = 1)
{
    for (int i = begin + delta; i <= end; i+=delta)
    {
        int j = i - delta;
        T temp = data[i];
        while (j >= begin && data[j] > temp)
        {
            data[j + delta] = data[j];
            j -= delta;
        }
        data[j + delta] = temp;
    }
}

template<class T>
void insertionSort(T* data, int size){
    insertionSort(data, 0, size - 1);
}

#endif /* insertion_sort_hpp */
