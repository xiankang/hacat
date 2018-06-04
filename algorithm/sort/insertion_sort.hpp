//
//  InsertionSort.hpp
//  hacat
//
//  Created by MacBook Pro on 2018/6/1.
//

#ifndef insertion_sort_hpp
#define insertion_sort_hpp

#include <stdio.h>

template<class T>
void insertionSort(T* data, int size){
    for(int i=1; i<size; i++){
        int j=i-1;
        T temp = data[i];
        while(j>=0 && data[j] > temp){
            data[j+1] = data[j];
            j -= 1;
        }
        data[j+1] = temp;
    }
}

#endif /* insertion_sort_hpp */
