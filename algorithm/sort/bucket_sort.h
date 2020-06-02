/*!
 * \file bucket_sort.h
 * \date 2020/06/01 15:44
 *
 * \author chenxiankang
 * Contact: wwwxiankang@163.com
 *
 * \brief 
 *
 * TODO: Ͱ����
 * Ͱ������ʵ�ǰ����ݰ���Χ���з��飬�ٶԷ����ڵ���������һ��������㷨��������
 * �����������С�����Ǽ��������ˣ�������ȴ��ֻ��˻�����ͨ������
 * \note
*/
#pragma once
#include <vector>

template<class T>
void bucket_sort(T* data, int size)
{
    if (size == 0)
        return;

    // find min value and max value
    int min = data[0];
    int max = data[0];
    for (int i = 1; i < size; ++i)
    {
        if (data[i] < min)
            min = data[i];
        if (data[i] > max)
            max = data[i];
    }
    //������10
    const int interval = 10;
    int c = min / interval;
    //ӳ�����
    //f(x) = x / interval - c;
    //��Ҫ����Ͱ�Ĵ�С
    //max / interval - min / interval + 1
    int bucket_size = max / interval - min / interval + 1;
    std::vector<std::vector<T>> buckets(bucket_size, std::vector<T>());
    for (int i = 0; i < size; ++i)
    {
        int bucket_index = data[i] / interval - c;
        buckets[bucket_index].push_back(data[i]);
    }
    //���ÿ��bucket��������
    for (int i = 0, j = 0; i < buckets.size(); ++i)
    {
        auto& bucket = buckets[i];
        heapSort(bucket.data(), bucket.size());
        //���ź����ֵ�Ż�ԭ����data��
        /*std::memcpy(data + j, bucket.data(), bucket.size() * sizeof(T));
        j += sizeof(T) * bucket.size();*/
		for (int i = 0; i < bucket.size(); ++i)
			data[j + i] = bucket[i];
		j += bucket.size();
    }
}