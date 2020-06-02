//
//  selection Sort
//  test
//  //选择排序
//  先选位置，再选择合适的数据交换到合适的位置
//  Created by MacBook Pro on 2018/6/2.
//
#pragma once

template<class T>
void selection_sort(T* data, int size)
{
	int min = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; ++j)
			if (data[min] > data[j])
				min = j;

		if (min != i)
		{
			auto temp = data[min];
			data[min] = data[i];
			data[i] = temp;
		}
	}
}