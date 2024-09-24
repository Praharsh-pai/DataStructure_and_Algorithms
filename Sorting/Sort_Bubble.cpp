#include <iostream>
// FUNCTION TO PERFORM BUBBLE SORT
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;//USED TO END CODE ONCE NO MORE SWAPING IS REQUIRED
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //SWAP FUNCTION
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
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

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
