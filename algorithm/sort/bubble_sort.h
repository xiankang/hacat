// bubble sort
//  
//  hacat
//  冒泡排序
//  n个数，需要冒泡n次，
//  对于每个数，冒泡到size - 1 - i的位置
//  冒泡趟数完了，排序结束
//  跟插入排序比较：插入排序是先选数据，再选择插入的位置，中途比较，会挪动数据的位置
//  冒泡排序其实是预留了一个位置，然后中途相邻比较，会挪动数据，直到把最小或者最大挪到预留的位置
//  跟选择排序比较：选择排序也是先选择一个位置，然后从剩下的数据里面选一个最小或最大，放入该位置，中途比较不移动数据
//  Created by MacBook Pro on 2018/6/1.
//

template<class T>
void bubble_sort(T* data, int size)
{
	for(int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				auto temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
}