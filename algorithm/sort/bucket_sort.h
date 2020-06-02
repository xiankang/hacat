/*!
 * \file bucket_sort.h
 * \date 2020/06/01 15:44
 *
 * \author chenxiankang
 * Contact: wwwxiankang@163.com
 *
 * \brief 
 *
 * TODO: 桶排序
 * 桶排序其实是把数据按范围进行分组，再对分组内的数据再用一般的排序算法进行排序，
 * 如果分组粒度小，就是计数排序了，如果粒度大，又会退化了普通排序了
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
    //区间是10
    const int interval = 10;
    int c = min / interval;
    //映射规则
    //f(x) = x / interval - c;
    //需要申请桶的大小
    //max / interval - min / interval + 1
    int bucket_size = max / interval - min / interval + 1;
    std::vector<std::vector<T>> buckets(bucket_size, std::vector<T>());
    for (int i = 0; i < size; ++i)
    {
        int bucket_index = data[i] / interval - c;
        buckets[bucket_index].push_back(data[i]);
    }
    //针对每个bucket进行排序
    for (int i = 0, j = 0; i < buckets.size(); ++i)
    {
        auto& bucket = buckets[i];
        heapSort(bucket.data(), bucket.size());
        //把排好序的值放回原来的data中
        /*std::memcpy(data + j, bucket.data(), bucket.size() * sizeof(T));
        j += sizeof(T) * bucket.size();*/
		for (int i = 0; i < bucket.size(); ++i)
			data[j + i] = bucket[i];
		j += bucket.size();
    }
}