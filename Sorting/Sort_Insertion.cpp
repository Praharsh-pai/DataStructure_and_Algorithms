#include <iostream>
//FUNCTION TO PERFORM INSERTION SORT
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        //MOVING ELEMENT TO CORRECT POSITION
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//FUNCTION TO PRINT ARRAY
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
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
    std::cout << "Unsorted array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
