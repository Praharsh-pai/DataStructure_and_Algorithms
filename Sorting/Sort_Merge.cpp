#include <iostream>
//MERGING FUNCTION
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    //TEMP FOR SAVING DATA
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];
    //MERGING
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    //ADDING REMAINING ELEMENTS
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
    //DELETING TEMP CREATED
    delete[] leftArr;
    delete[] rightArr;
}
//MERGE SORT FUNCTION
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        merge(arr, left, mid, right);
    }
}
//FUNCTION TO PRINT ARRAY
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//MAIN FUNCTION
int main() {
    int n = 0;
    std::cout << "Enter Number of Elements to be sorted: ";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cout<<"enter " << i+1 << " number:";
        std::cin>>arr[i];
    }

    std::cout << "Unsorted Array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}



