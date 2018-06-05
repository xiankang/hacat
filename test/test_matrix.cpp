//
//  test_matrix.cpp
//  test
//
//  Created by MacBook Pro on 2018/6/4.
//

#include "test_matrix.hpp"
#include "../algorithm/divide_conquer/matrix.hpp"

template<class T>
class MatrixTask: public TaskBase {
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
};

TestMatrix::TestMatrix() {
    Matrix<int> m1(100,100);
    Matrix<int> m2(100,100);
    addTask(new MatrixTask<int>(m1, m2));
}
