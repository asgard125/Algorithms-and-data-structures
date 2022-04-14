int get_kth(int *pInt, int mid, int left, int i, int size);

using namespace std;

void swap_ind(int arr[], int ind1, int ind2){
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}


int partition5(int list[], int left, int right){
    int i = left + 1;
    while (i <= right){
        int j = i;

        while (j > left and list[j - 1] > list[j]) {
            swap_ind(list, j - 1, j);
            j--;
        }
        i++;
    }
    return (left + right) / 2;
}


int partition(int arr[], int left, int right, int pivot, int k){
    int pivotVal = arr[pivot];
    swap_ind(arr, pivot, right);
    int tempInd = left;
    for (int i = left; i < right; i++){
        if (arr[i] < pivotVal){
            swap_ind(arr, tempInd, i);
            tempInd++;
        }
    }
    int tempInd2 = tempInd;
    for (int i = tempInd2; i < right; i++){
        if (arr[i] == pivotVal){
            swap_ind(arr, tempInd2, i);
            tempInd2++;
        }
    }
    swap_ind(arr, right, tempInd2);
    if (k < tempInd){
        return tempInd;
    }else if(k <= tempInd2){
        return k;
    }
    return tempInd2;
}

int pivot(int arr[], int left, int right, int arr_size){
    if (right - left < 5){
        return partition5(arr, left, right);
    }
    for (int i = left; i <= right; i+=5){
        int subRight = i + 4;
        if (subRight > right){
            subRight = right;
        }
        int median5 = partition5(arr, i, subRight);
        swap_ind(arr, median5, left + (i - left) / 5);

    }
    int mid = (right - left) / 10 + left + 1;
    return get_kth(arr, mid, left, left + (right - left) / 5, arr_size);
}

int get_kth(int arr[], int k, int left, int right, int arr_size){
    if (arr_size == 1){
        return 0;
    }
    while (true){
        if (left == right){
            return left;
        }
        int pivotInd = pivot(arr, left, right, arr_size);
        pivotInd = partition(arr, left, right, pivotInd, k);
        if (k == pivotInd){
            return k;
        }else if(k < pivotInd){
            right = pivotInd - 1;
        }else{
            left = pivotInd + 1;
        }
    }
}

int get_median(int arr[], int arr_size){
    return get_kth(arr, (arr_size - 1) / 2, 0, arr_size - 1, arr_size);
}

