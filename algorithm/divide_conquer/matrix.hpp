//
//  matrix.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/4.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include "../../base/object.hpp"
#include <sstream>
#include <iostream>

template<class T>
class Matrix : public Object{
private:
    int row_;
    int column_;
    void allocate();
    void copy(T** data);
    void clear();
public:
    T** data_;
    int row() { return row_; }
    int column() { return column_; }
    Matrix();
    Matrix(int row, int column);
    Matrix(Matrix& m1);
    ~Matrix();
    Matrix multiply(Matrix& m1);
    Matrix multiply2(Matrix& m1);
    Matrix multiply3(Matrix& m1);
    std::string toString();
};

template<class T>
Matrix<T>::Matrix():row_(0),column_(0),data_(nullptr) {

}

template<class T>
Matrix<T>::Matrix(int row, int column):row_(row),column_(column),data_(nullptr){
    //data
    allocate();
}

template<class T>
Matrix<T>::Matrix(Matrix<T>& m1):row_(m1.row()),column_(m1.column()),data_(nullptr) {
    copy(m1.data_);
}

template<class T>
Matrix<T>::~Matrix() {
    clear();
}

template<class T>
void Matrix<T>::allocate() {
    data_ = new T*[row_];
    for(int i=0; i < row_; i++){
        data_[i] = new T[column_];
        for(int j=0; j<column_; j++){
            data_[i][j] = rand() % 100;
        }
    }
}

template<class T>
void Matrix<T>::copy(T** data) {
    if(data_ == nullptr) {
        data_ = new T* [row_];
        for(int i=0; i<row_; i++) {
            data_[i] = new T[column_];
        }
    }
    
    for(int i=0; i<row_;i++){
        memcpy(data_[i], data[i], column_ * sizeof(T));
    }
}
template<class T>
void Matrix<T>::clear() {
    if(data_ == nullptr)
        return;
    
    for(int i=0; i < row_; i++){
        delete [] data_[i];
    }
    delete [] data_;
    data_ = nullptr;
}

template<class T>
Matrix<T> Matrix<T>::multiply(Matrix<T>& m1) {
    if(column_ != m1.row()){
        Matrix<T> empty;
        return empty;
    }
    Matrix<T> result(row_, m1.column());
    for(int i=0; i < row_; i++){
        for(int j=0; j< m1.column(); j++){
            T ij = 0;
            for(int k=0; k<column_; k++) {
                ij += data_[i][k] * m1.data_[k][j];
            }
            result.data_[i][j] = ij;
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::multiply2(Matrix<T>& m1) {
    if(column_ != m1.row()){
        Matrix<T> empty;
        return empty;
    }
    Matrix<T> result(row_, m1.column());
    for(int i=0; i < row_; i++){
        for(int j=0; j< m1.column(); j++){
            T ij = 0;
            for(int k=0; k<column_; k++) {
                ij += data_[i][k] * m1.data_[k][j];
            }
            result.data_[i][j] = ij;
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::multiply3(Matrix<T>& m1) {
    if(column_ != m1.row()){
        Matrix<T> empty;
        return empty;
    }
    Matrix<T> result(row_, m1.column());
    for(int i=0; i < row_; i++){
        for(int j=0; j< m1.column(); j++){
            T ij = 0;
            for(int k=0; k<column_; k++) {
                ij += data_[i][k] * m1.data_[k][j];
            }
            result.data_[i][j] = ij;
        }
    }
    return result;
}
template<class T>
std::string Matrix<T>::toString() {
    std::ostringstream ost;
    for(int i=0; i<row_; i++) {
        for(int j=0; j<column_; j++){
            ost<<data_[i][j]<<" ";
        }
        ost<<std::endl;
    }
    return ost.str();
}
#endif /* matrix_hpp */
