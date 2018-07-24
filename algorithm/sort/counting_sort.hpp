#include <memory>
#include <map>

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
