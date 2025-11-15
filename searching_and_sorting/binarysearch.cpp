#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int low, int high, int search, int* arr, int n);

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    int* arr = new int[n];
    for(int i = 0;i < n;i++){
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;
    int search;

    cout << "Enter element you want to search: ";
    cin >> search;

    int index = binarySearch(low, high, search, arr, n);
    cout << "Found at " << index << "th index";

    return 0;
}

int binarySearch(int low, int high, int search, int* arr, int n){
    if(low > high) return -1;

    int mid = floor((low + high) / 2);

    if(search == arr[mid]) return mid;

    if(search > arr[mid]){
        low = mid + 1;
        return binarySearch(low, high, search, arr, n);
    }

    if (search < arr[mid]){
        high = mid - 1;
        return binarySearch(low, high, search, arr, n);
    }
}