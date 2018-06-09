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
#include <memory>
#include <vector>

template<class T>
class Matrix : public Object{
private:
    int row_;
    int column_;
    int offset_x_;
    int offset_y_;
    void allocate();
    std::shared_ptr<std::vector<std::vector<T>>> data_;
public:
    int row() { return row_; }
    int column() { return column_; }
    //override operator() for read
    T data(int x, int y) const;
    //override operator() for write
    T& data(int x, int y);
    std::vector<T>& data(int x);
    Matrix();
    Matrix(int row, int column);
    Matrix(const Matrix& m1);
    Matrix& operator=(const Matrix& m1);
    //get sub matrix
    Matrix(const Matrix& m1, int offset_x, int offset_y, int row, int column);
    ~Matrix();
    Matrix clone();
    void copyTo(const Matrix& m1);
    Matrix multiply(const Matrix& m1);
    std::string toString();
};

template<class T>
Matrix<T>::Matrix():row_(0),column_(0),offset_x_(0),offset_y_(0) {

}

template<class T>
Matrix<T>::Matrix(int row, int column):row_(row),column_(column),offset_x_(0),offset_y_(0){
    //data
    allocate();
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m1):row_(m1.row_),column_(m1.column_),offset_x_(m1.offset_x_),offset_y_(m1.offset_y_),data_(m1.data_) {
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &m1) {
    if(&m1 != this) {
        row_ = m1.row_;
        column_ = m1.column_;
        offset_x_ = m1.offset_x_;
        offset_y_ = m1.offset_y_;
        data_ = m1.data_;
    }
    return *this;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m1, int offset_x, int offset_y, int row, int column):row_(row),column_(column),offset_x_(m1.offset_x_ + offset_x),offset_y_(m1.offset_y_+offset_y),data_(m1.data_) {
}

template<class T>
Matrix<T>::~Matrix() {

}

template<class T>
void Matrix<T>::allocate() {
    data_ = std::shared_ptr<std::vector<std::vector<T>>>(new std::vector<std::vector<T>>());
    for(int i=0; i < row_; i++){
        std::vector<T> column_data;
        for(int j=0; j < column_; j++){
            column_data.push_back(rand() % 100);
        }
        data_->push_back(column_data);
    }
}

template<class T>
Matrix<T> Matrix<T>::clone() {
    Matrix<T> matrix(row_, column_);
    for(int i=0; i<row_;i++){
        memcpy(matrix.data(i).data() + offset_y_, data(i).data() + offset_y_, column_ * sizeof(T));
    }
    
    return matrix;
}

template<class T>
void Matrix<T>::copyTo(const Matrix<T> &m1) {
    m1 = clone();
}

template<class T>
T Matrix<T>::data(int x, int y) const {
    return (*data_)[offset_x_ + x][offset_y_ + y];
}

template<class T>
T& Matrix<T>::data(int x, int y) {
    return (*data_)[offset_x_ + x][offset_y_ + y];
}

template<class T>
std::vector<T>& Matrix<T>::data(int x) {
    return (*data_)[offset_x_ + x];
}

template<class T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& m1) {
    if(column_ != m1.row_){
        Matrix<T> empty;
        return empty;
    }
    Matrix<T> result(row_, m1.column_);
    for(int i=0; i < row_; i++){
        for(int j=0; j< m1.column_; j++){
            T ij = 0;
            for(int k=0; k<column_; k++) {
                ij += data(i,k) * m1.data(k,j);
            }
            result.data(i,j) = ij;
        }
    }
    return result;
}

template<class T>
std::string Matrix<T>::toString() {
    std::ostringstream ost;
    for(int i=0; i<row_; i++) {
        for(int j=0; j<column_; j++){
            ost<<data(i,j)<<" ";
        }
        ost<<std::endl;
    }
    return ost.str();
}
#endif /* matrix_hpp */
