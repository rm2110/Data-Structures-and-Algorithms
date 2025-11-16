#include<iostream>
using namespace std;

class qSort {
    public:
        int* arr;
        int size;

        qSort(int size) {
            this->size = size;
            arr = new int[size];
            
            input();
            quickSort(0, size - 1); // call quicksort
            cout << "Sorted array: ";
            print();
        }

        void input() {
            for (int i = 0; i < size; i++) {
                cout << "Enter " << i << "th element: ";
                cin >> arr[i];
            }
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

        int partition(int low, int high) {
            int pivot = arr[high]; // choose last element as pivot
            int i = low - 1;      // index of smaller element

            for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {  
                    i++;
                    swap(arr[i], arr[j]);  
                }
            }
            swap(arr[i + 1], arr[high]);  
            return i + 1; // pivot index
        }

        // Recursive quicksort
        void quickSort(int low, int high) {
            if (low < high) {
                int pi = partition(low, high);

                // Recursively sort left & right subarrays
                quickSort(low, pi - 1);
                quickSort(pi + 1, high);
            }
        }

        ~qSort() {
            delete[] arr;
        }
};

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    qSort myObj(size);

    return 0;
}
