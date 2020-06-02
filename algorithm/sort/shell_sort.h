/*!
 * \file shell_sort.h
 * \date 2020/06/01 15:42
 *
 * \author chenxiankang
 * Contact: wwwxiankang@163.com
 *
 * \brief 
 *
 * TODO: 希尔排序
 * 先对数组总数的一半的delta进行分组，对分组进行插入排序
 * 逐渐缩小delta，直到1，这时候已经接近有序了，所以插入排序效率高，
 * 但是分组后，同样的数可能因为分组而调换，所以希尔排序是不稳定的
 * \note
*/

#pragma once

#include "insertion_sort.hpp"

template<class T>
void shell_sort(T* data, int begin, int end)
{
    int size = (end - begin) + 1;

    for (int delta = size / 2; delta > 0; delta /= 2)
        for (int i = 0; i < delta; ++i)
            insertionSort(data, begin + i, end, delta);
}

template<class T>
void shell_sort(T* data, int size)
{
    shell_sort(data, 0, size - 1);
}