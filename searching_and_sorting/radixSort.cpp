#include<iostream>
using namespace std;

class rSort{
    public:
        int* arr;
        int size;

        rSort(int size){
            this->size = size;
            arr = new int[size];

            input();
            radixSort();
        }

        void input(){
            for(int i = 0;i < size; i++){
                cout << "Enter " << i << "th element: ";
                cin >> arr[i];
            }
        }

        int getMax(int* arr, int size) {
            int max = arr[0];
            for (int i = 1; i < size; i++) {
                if (arr[i] > max) max = arr[i];
            }
            return max;
        } 

        void print(){
            for(int i = 0;i < size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

        void countingSort(int* arr, int size, int place) {
            const int max = 10;
            int output[size];
            int count[max];

            for (int i = 0; i < max; ++i)
                count[i] = 0;

            // Calculate count of elements
            for (int i = 0; i < size; i++)
                count[(arr[i] / place) % 10]++;

            // Calculate cumulative count
            for (int i = 1; i < max; i++)
                count[i] += count[i - 1];

            // Place the elements in sorted order
            for (int i = size - 1; i >= 0; i--) {
                output[count[(arr[i] / place) % 10] - 1] = arr[i];
                count[(arr[i] / place) % 10]--;
            }

            for (int i = 0; i < size; i++)
                 arr[i] = output[i];
        }

        void radixSort(){
            int max = getMax(arr, size);

            // Apply counting sort to sort elements based on place value.
            for (int place = 1; max / place > 0; place *= 10)
                countingSort(arr, size, place);

            cout << "Sorted list: ";
            print();
        }

        ~rSort(){
            delete[] arr;
        }
};

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;

    rSort myObj(size);

    return 0;
}