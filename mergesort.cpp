#include <stdio.h>
#include <cstdlib>

void merge(int* arr, long long l, long long r)
{
    if (l == r) {
        return;
    }
    long long mid = (l + r) / 2;
    long long left_iter = l;
    long long right_iter = mid + 1;
    merge(arr, left_iter, mid);
    merge(arr, right_iter, r);
    int* tmp = (int*)malloc((r + 1) * 4);
    for (long long iter = l; iter < r + 1; iter++)
    {
        if ((right_iter > r) || ((left_iter <= mid) && (arr[left_iter] <= arr[right_iter])))
        {
            tmp[iter - l] = arr[left_iter];
            left_iter++;
        }
        else
        {
            tmp[iter - l] = arr[right_iter];
            right_iter++;
        }
    }
    for (long long iter = 0; iter < r - l + 1; iter++)
        arr[l + iter] = tmp[iter];
    free(tmp);
}