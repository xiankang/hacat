//
//  MergeSort.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/2.
//

#ifndef merge_sort_hpp
#define merge_sort_hpp

#include <stdio.h>
template<class T>
void merge(T* data, int start, int center, int end){
    
    int lLength = center-start + 1;
    int rLength = end-center;
    T* lData = new T[lLength];
    T* rData = new T[rLength];
    for(int i=start; i<=center; i++){
        lData[i-start] = data[i];
    }
    for(int i=center+1; i<=end; i++){
        rData[i-center-1] = data[i];
    }
    
    int i=0;
    int j=0;
    
    for(int k=start; k<=end; k++){
        if(i==lLength){
            data[k] = rData[j];
            j = j + 1;
        }else if(j==rLength){
            data[k] = lData[i];
            i = i + 1;
        } else {
            if(lData[i] < rData[j]){
                data[k] = lData[i];
                i = i + 1;
            } else {
                data[k] = rData[j];
                j = j + 1;
            }
        }
    }
    
    delete [] lData;
    delete [] rData;
}

template<class T>
void mergeSort(T* data, int start, int end){
    if(start < end){
        int center = (start + end) / 2;
        MergeSort(data, start, center);
        MergeSort(data, center + 1, end);
        Merge(data, start, center, end);
    }
}


#endif /* merge_sort_hpp */
