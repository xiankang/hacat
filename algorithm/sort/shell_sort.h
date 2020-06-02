/*!
 * \file shell_sort.h
 * \date 2020/06/01 15:42
 *
 * \author chenxiankang
 * Contact: wwwxiankang@163.com
 *
 * \brief 
 *
 * TODO: ϣ������
 * �ȶ�����������һ���delta���з��飬�Է�����в�������
 * ����Сdelta��ֱ��1����ʱ���Ѿ��ӽ������ˣ����Բ�������Ч�ʸߣ�
 * ���Ƿ����ͬ������������Ϊ���������������ϣ�������ǲ��ȶ���
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