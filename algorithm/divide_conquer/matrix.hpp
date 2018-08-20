//
//  matrix.hpp
//  test
//
//  Created by MacBook Pro on 2018/6/4.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include "base/object.hpp"
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

template<class T>
class Matrix : public Object{
private:
    int row_;
    int column_;
    int offset_r_;
    int offset_c_;
    void allocate();
    std::shared_ptr<std::vector<std::vector<T>>> data_;
public:
    int row() { return row_; }
    int column() { return column_; }
    bool isEmpty() const { return row_ == 0 || column_ == 0;}
    //override operator() for read
    T data(int x, int y) const;
    //override operator() for write
    T& data(int x, int y);
    std::vector<T>& data(int x);
    std::vector<T>& data(int x) const;
    Matrix();
    Matrix(int row, int column);
    Matrix(const Matrix& m1);
    Matrix& operator=(const Matrix& m1);
    Matrix operator*(const Matrix& m1);
    Matrix operator+(const Matrix& m1);
    //get sub matrix
    Matrix(const Matrix& m1, int offset_r, int offset_c, int row, int column);
    ~Matrix();
    Matrix clone() const;
    void copyTo(Matrix& m1) const;
    //normal method
    Matrix multiply(const Matrix& m1);
    //divide and conquar method
    Matrix multiply2(const Matrix& m1);
    
    static void add(const Matrix& m1, const Matrix& m2, Matrix& result);
    static void multiply(const Matrix& m1, const Matrix& m2, Matrix& result);
    static void mergeMultiply(const Matrix& m1, const Matrix& m2, Matrix& result);
    std::string toString() const;
};

template<class T>
Matrix<T>::Matrix():row_(0),column_(0),offset_r_(0),offset_c_(0) {

}

template<class T>
Matrix<T>::Matrix(int row, int column):row_(row),column_(column),offset_r_(0),offset_c_(0){
    //data
    allocate();
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m1):row_(m1.row_),column_(m1.column_),offset_r_(m1.offset_r_),offset_c_(m1.offset_c_),data_(m1.data_) {
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &m1) {
    if(&m1 != this) {
        row_ = m1.row_;
        column_ = m1.column_;
        offset_r_ = m1.offset_r_;
        offset_c_ = m1.offset_c_;
        data_ = m1.data_;
    }
    return *this;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m1, int offset_r, int offset_c, int row, int column):row_(row),column_(column),offset_r_(m1.offset_r_ + offset_r),offset_c_(m1.offset_c_+offset_c),data_(m1.data_) {
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
Matrix<T> Matrix<T>::clone() const{
    Matrix<T> matrix(row_, column_);
    for(int i=0; i<row_;i++){
        memcpy(matrix.data(i).data() + matrix.offset_c_, data(i).data() + offset_c_, column_ * sizeof(T));
    }
    
    return matrix;
}

template<class T>
void Matrix<T>::copyTo(Matrix<T> &m1) const{
    if(row_ == m1.row_ && column_ == m1.column_){
        for(int i=0; i<row_;i++){
            memcpy(m1.data(i).data() + m1.offset_c_, data(i).data() + offset_c_, column_ * sizeof(T));
        }
    } else {
        m1 = clone();
    }
}

template<class T>
T Matrix<T>::data(int x, int y) const {
    return (*data_)[offset_r_ + x][offset_c_ + y];
}

template<class T>
T& Matrix<T>::data(int x, int y) {
    return (*data_)[offset_r_ + x][offset_c_ + y];
}

template<class T>
std::vector<T>& Matrix<T>::data(int x) {
    return (*data_)[offset_r_ + x];
}

template<class T>
std::vector<T>& Matrix<T>::data(int x) const{
    return (*data_)[offset_r_ + x];
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m1) {
    Matrix<T> result;
    Matrix<T>::multiply(*this, m1, result);
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m1) {
    Matrix<T> result(row_,column_);
    Matrix<T>::add(*this, m1, result);
    return result;
}

template<class T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& m1) {
    Matrix<T> result;
    Matrix<T>::multiply(*this, m1, result);
    return result;
}

template<class T>
void Matrix<T>::mergeMultiply(const Matrix<T>& m1, const Matrix<T>& m2, Matrix<T>& result) {
    if(m1.isEmpty() || m2.isEmpty())
        return;
    
    if(m1.row_ == 1 && m1.column_==1 && m2.row_==1 && m2.column_==1) {
        result.data(0, 0) = m1.data(0, 0) * m2.data(0, 0);
    } else {
        int offset_c = ceil(m1.column_ / 2.0);
        int offset_r = ceil(m1.row_ / 2.0);
        int offset_c_2 = ceil(m2.column_ / 2.0);
        int offset_r_2 = ceil(m2.row_ / 2.0);
        //partial m1
        Matrix<T> m1_a(m1, 0, 0, offset_r, offset_c);
        Matrix<T> m1_b(m1, 0, offset_c, offset_r, m1.column_-offset_c);
        Matrix<T> m1_c(m1, offset_r, 0, m1.row_ - offset_r, offset_c);
        Matrix<T> m1_d(m1, offset_r, offset_c, m1.row_ - offset_r, m1.column_ - offset_c);
        //partial m2
        Matrix<T> m2_a(m2, 0, 0, offset_r_2, offset_c_2);
        Matrix<T> m2_b(m2, 0, offset_c_2, offset_r_2, m2.column_ - offset_c_2);
        Matrix<T> m2_c(m2, offset_r_2, 0, m2.row_ - offset_r_2, offset_c_2);
        Matrix<T> m2_d(m2, offset_r_2, offset_c_2, m2.row_ - offset_r_2, m2.column_ - offset_c_2);
        //partial result
        Matrix<T> r_a(result, 0, 0, m1_a.row_, m2_a.column_);
        Matrix<T> r_b(result, 0, m2_a.column_, m1_b.row_, m2_b.column_);
        Matrix<T> r_c(result, m1_a.row_, 0, m1_c.row_, m2_c.column_);
        Matrix<T> r_d(result, m1_a.row_, m2_a.column_, m1_d.row_, m2_d.column_);
        
        Matrix<T> t1,t2;
        if(r_a.row_!=0 && r_a.column_!=0) {
//            t1 = m1_a * m2_a;
//            t2 = m1_b * m2_c;
            t1 = m1_a.multiply2(m2_a);
            t2 = m1_b.multiply2(m2_c);
            add(t1, t2, r_a);
        }
        if(r_b.row_!=0 && r_b.column_!=0){
//            t1 = m1_a * m2_b;
//            t2 = m1_b * m2_d;
            t1 = m1_a.multiply2(m2_b);
            t2 = m1_b.multiply2(m2_d);
            add(t1, t2, r_b);
        }
        if(r_c.row_!=0 && r_c.column_!=0){
//            t1 = m1_c * m2_a;
//            t2 = m1_d * m2_c;
            t1 = m1_c.multiply2(m2_a);
            t2 = m1_d.multiply2(m2_c);
            add(t1, t2, r_c);
        }
        if(r_d.row_!=0 && r_d.column_!=0){
//            t1 = m1_c * m2_b;
//            t2 = m1_d * m2_d;

            t1 = m1_c.multiply2(m2_b);
            t2 = m1_d.multiply2(m2_d);
            add(t1, t2, r_d);
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::multiply2(const Matrix<T>& m1) {
    if(column_ != m1.row_ || isEmpty() || m1.isEmpty()){
        Matrix<T> empty;
        return empty;
    }
    Matrix<T> result(row_, m1.column_);
    mergeMultiply(*this, m1, result);
    return result;
}

template<class T>
void Matrix<T>::multiply(const Matrix<T>& m1, const Matrix<T>& m2, Matrix<T>& result) {
    if(m1.column_ != m2.row_ || m1.isEmpty() || m2.isEmpty()){
        std::cerr<<"Matrix::multiply column of left matrix not equal row of right matrix!"<<std::endl;
        return;
    }
    
    result = Matrix<T> (m1.row_, m2.column_);
    for(int i=0; i < m1.row_; i++){
        for(int j=0; j< m2.column_; j++){
            T ij = 0;
            for(int k=0; k<m1.column_; k++) {
                ij += m1.data(i,k) * m2.data(k,j);
            }
            result.data(i,j) = ij;
        }
    }
}

template<class T>
void Matrix<T>::add(const Matrix<T>& m1, const Matrix<T>& m2, Matrix<T>& result) {
    if(m1.isEmpty() && m2.isEmpty())
        return;
    else if(m1.isEmpty() && !m2.isEmpty())
        m2.copyTo(result);
    else if(!m1.isEmpty() && m2.isEmpty())
        m1.copyTo(result);
    else {
        for(int i=0;i<m1.row_;i++) {
            for(int j=0;j<m1.column_;j++){
                result.data(i, j) = m1.data(i, j) + m2.data(i, j);
            }
        }
    }
}

template<class T>
std::string Matrix<T>::toString() const{
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
