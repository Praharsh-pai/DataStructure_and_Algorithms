#include <iostream>
using namespace std;

//SWAP FUNCTION
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//PARTITION FUNCTION
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// FUNCTION TO PERFORM DIVIDE FUNCTION
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// FUNCTION TO PRINT THE ARRAY
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//MAIN FUNCTION
int main() {
 int n = 0;
    cout << "Enter Number of Elements to be sorted: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter " << i+1 << " number:";
        cin>>arr[i];
    }
    cout << "Unsorted Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
