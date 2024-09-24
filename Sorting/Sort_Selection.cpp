#include <iostream>
// FUNCTION TO PERFORM SELECTION SORT
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //SWAP FUNCTION
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// FUNCTION TO PRINT THE ARRAY
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
    std::cout << "Unsorted Array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
