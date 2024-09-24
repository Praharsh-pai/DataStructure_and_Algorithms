#include <iostream>
using namespace std;


//max heap
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}


//min heap
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapSortMax(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapSortMax(arr, i, 0);
    }
}

void heapSortMin(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int n=0;
    cout<<"Enter Number of Elements to be sorted: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter "<< i+1 <<" number:";
        cin>>arr[i];
    }
    cout<<"Unsorted array: ";
    printArray(arr,n);

    heapSortMin(arr,n);

    cout<<"Sorted array: ";
    printArray(arr, n);

    heapSortMax(arr,n);

    cout<<"Sorted array: ";
    printArray(arr, n);
    return 0;

}
