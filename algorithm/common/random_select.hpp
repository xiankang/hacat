// 随机从M个不相同的数里面随机取N个不同的数
//如果n大于length的一半，则随机剩下的来进行优化

template <class T>
void random_select(T *data, int length, T *result, int n)
{
    if (n < 0)
    {
        result = nullptr;
        return;
    }
    if (n >= length)
    {
        result = data;
        return;
    }

    int r_n = n <= length / 2 ? n : length - n;

    for (int i = 0; i < r_n; i++)
    {
        int swap_index = length - i;
        int index = rand() % swap_index;
        T temp = data[index];
        data[index] = data[swap_index - 1];
        data[swap_index - 1] = temp;
    }

    if(r_n == n)
        result = data + (length - 1 - n);
    else
        result = data;
}