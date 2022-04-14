int arr_partition(int arr[], int left, int right){
    int pivot;
    if (right - left == 0){
        pivot = left;
    }else {
        pivot = rand() % (right - left) + left;
    }
    if (left != right){
        int temp = arr[right];
        arr[right] = arr[pivot];
        arr[pivot] = temp;
    }
    int last = arr[right];
    int i = left - 1;
    for (int j = left; j < right + 1; j++){
        if (arr[j] <= last){
            int temp = arr[j];
            arr[j] = arr[++i];
            arr[i] = temp;
        }
    }
    return i;
}


int get_median(int arr[], int k, int arr_size){
    int left = 0;
    int right = arr_size - 1;
    if (arr_size < 2){
        return arr[0];
    }
    while (true){
        int mid = arr_partition(arr, left, right);

        if (mid == k) {
            return arr[mid];
        }
        else if (k < mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
}