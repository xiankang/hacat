//
//  find_maximum_subarray.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/3.
//

#ifndef find_maximum_subarray_hpp
#define find_maximum_subarray_hpp

#include <stdio.h>
#include "base/object.hpp"
#include <sstream>

template<class T>
class SubarrayResult :public Object {
public:
    int low_;
    int high_;
    T sum_;

    SubarrayResult(){}
    
    SubarrayResult(int low, int high, T sum){
        low_ = low;
        high_ = high;
        sum_ = sum;
    }
    
    SubarrayResult(const SubarrayResult<T> &subarrayResult){
        low_ = subarrayResult.low_;
        high_ = subarrayResult.high_;
        sum_ = subarrayResult.sum_;
    }
    
//    SubarrayResult<T>& operator=(const SubarrayResult<T> &subarrayResult) {
//        low_ = subarrayResult.low_;
//        high_ = subarrayResult.high_;
//        sum_ = subarrayResult.sum_;
//        return *this;
//    }
    
    std::string toString() {
        std::ostringstream ostr;
        ostr<<"low="<<low_<<" high="<<high_<<" sum="<<sum_;
        return ostr.str();
    }
};

template<class T>
SubarrayResult<T> findMaxCrossingSubarray(T* data, int low, int mid, int high) {
    T left_sum = data[mid];
    T sum = left_sum;
    int max_left = mid;
    for(int i=mid - 1; i>= low; i--){
        sum += data[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    
    T right_sum = data[mid + 1];
    sum = right_sum;
    int max_right = mid + 1;
    for(int i = mid + 2; i<=high; i++){
        sum += data[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    
    SubarrayResult<T> cross_result(max_left, max_right, left_sum+right_sum);
    return cross_result;
}

template<class T>
SubarrayResult<T> findMaximumSubarray(T* data, int low, int high) {
    if(low == high){
        SubarrayResult<T> subarray_result(low, high, data[low]);
        return subarray_result;
    } else {
        int mid = (low + high) / 2;
        SubarrayResult<T> left_result = findMaximumSubarray(data, low, mid);
        SubarrayResult<T> right_result = findMaximumSubarray(data, mid + 1, high);
        SubarrayResult<T> cross_result = findMaxCrossingSubarray(data, low, mid, high);
        
        if(left_result.sum_ >= right_result.sum_ && left_result.sum_ >= cross_result.sum_){
            return left_result;
        } else if (right_result.sum_ >= left_result.sum_ && right_result.sum_ >= cross_result.sum_){
            return right_result;
        } else {
            return cross_result;
        }
    }
}

template<class T>
SubarrayResult<T> findMaximumSubarray2(T* data, int low, int high){
    SubarrayResult<T> result(low, low, data[low]);
    T sum = result.sum_;
    int mark = 0;
    int try_start = low;
    for(int i = low + 1; i<=high; i++){
        sum += data[i];
        if(sum < 0) {
            sum = 0;
            mark = 1;
        } else {
            if(mark == 1) {
                mark = 0;
                try_start = i;
            }
            if(sum >= result.sum_) {
                result.high_ = i;
                result.sum_ = sum;
                result.low_ = try_start;
            }
        }
    }
    
    return result;
}
#endif /* find_maximum_subarray_hpp */
