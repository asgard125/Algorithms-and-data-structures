void quick_sort(int* s_arr, int first, int last)
{
    int temp;
    int i = first, j = last, x = s_arr[(first + last) / 2];

    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;

        if(i <= j) {
            if (s_arr[i] > s_arr[j]){
                temp = s_arr[i];
                s_arr[i] = s_arr[j];
                s_arr[j] = temp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        quick_sort(s_arr, i, last);
    if (first < j)
        quick_sort(s_arr, first, j);
}

