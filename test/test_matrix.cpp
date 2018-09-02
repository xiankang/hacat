//
//  test_matrix.cpp
//  test
//
//  Created by MacBook Pro on 2018/6/4.
//

#include "test_matrix.hpp"
#include "divide_conquer/matrix.hpp"

template<class T>
class MatrixTask: public ITask {
private:
    Matrix<T> m1_;
    Matrix<T> m2_;
public:
    void run() {
        std::cout<<"m1 * m2"<<std::endl;
        std::cout<<(m1_.multiply(m2_)).toString();
    }
    
    MatrixTask(Matrix<T>& m1, Matrix<T>& m2):m1_(m1),m2_(m2){
        std::cout<<"m1"<<std::endl;
        std::cout<<m1_.toString()<<std::endl;
        std::cout<<"m2"<<std::endl;
        std::cout<<m2_.toString()<<std::endl;
    }
    ~MatrixTask(){}
};

template<class T>
class MatrixTask2: public ITask {
private:
    Matrix<T> m1_;
    Matrix<T> m2_;
public:
    void run() {
        std::cout<<"m1 * m2"<<std::endl;
        std::cout<<(m1_.multiply2(m2_)).toString();
    }
    
    MatrixTask2(Matrix<T>& m1, Matrix<T>& m2):m1_(m1),m2_(m2){
        std::cout<<"m1"<<std::endl;
        std::cout<<m1_.toString()<<std::endl;
        std::cout<<"m2"<<std::endl;
        std::cout<<m2_.toString()<<std::endl;
    }
    ~MatrixTask2(){}
};

TestMatrix::TestMatrix() {
    Matrix<int> m1(51,51);
    Matrix<int> m2(51,51);
}
