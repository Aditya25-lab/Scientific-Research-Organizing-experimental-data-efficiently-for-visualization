#include <iostream>
using namespace std;

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printData(double arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    double data[] = {23.4, 45.6, 12.7, 34.8, 29.9, 42.1, 15.3};
    int n = sizeof(data) / sizeof(data[0]);
    printData(data, n);
    quickSort(data, 0, n - 1);
    printData(data, n);
    return 0;
}
