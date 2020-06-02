// counting sort
//  
//  hacat
//  计数排序
//  统计每个数的数量，然后按顺序输出数
//  Created by MacBook Pro on 2018/6/1.
//

#pragma once
#include <memory>
#include <map>
#include <math.h>

void countingSort(int* data, int length, int max) {
    int* temp = new int[length];
    memcpy(temp, data, length * sizeof(int));

    int* c = new int[max];
    for(int i=0; i< max; i++) {
        c[i] = 0;
    }

    for(int i=0; i<length; i++) {
        c[temp[i]] += 1;
    }

    for(int i=1; i<max; i++) {
        c[i] += c[i-1];
//        std::cout<<"c"<<c[i]<< " ";
    }
    
    //
    for(int i=length-1;i>=0;i--){
        data[c[temp[i]]-1] = temp[i];
        c[temp[i]] -= 1;
    }
    delete [] temp;
    delete [] c;
}

int getRadix(int num, int d) {
    int p = pow(10, d - 1);
    return num / p % 10;
}

void countingSortForRadix(int* data, int length, int d) {
    //按第几位排序
    int* temp = new int[length];
    memcpy(temp, data, length * sizeof(int));

    //10进制
    int c[10];
    for(int i=0; i< 10; i++) {
        c[i] = 0;
    }

    for(int i=0; i<length; i++) {
        int radix = getRadix(temp[i], d);
        c[radix] += 1;
    }

    for(int i=1; i<10; i++) {
        c[i] += c[i-1];
//        std::cout<<"c"<<c[i]<< " ";
    }
    
    //
    for(int i=length-1;i>=0;i--){
        int radix = getRadix(temp[i], d);
        data[c[radix]-1] = temp[i];
        c[radix] -= 1;
    }
    delete [] temp;
}
