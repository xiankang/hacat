#pragma once


template<class T>
int partial(T* data, int q, int r) {
    int k = data[r];
    int j=q-1;
    for(int i=q; i <= r-1; i++) {
        if(data[i]<=k){
            j++;
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    T temp = data[j+1];
    data[j+1] = k;
    data[r] = temp;
    return j+1;
}

template<class T>
int randomPartial(T* data, int q, int r) {
    //加入随机选取主元
    int random = q + (rand() % (r - q + 1));
    T temp = data[random];
    data[random] = data[r];
    data[r] = temp;

    return partial(data, q, r);
}

template<class T>
void quickSort(T* data, int q, int r) {
    if(q<r){
        int m = randomPartial(data, q, r);
        quickSort(data, q, m-1);
        quickSort(data, m+1, r);
    }
}
