#include<iostream>
using namespace std;

class sllSort{
    public:
        int* arr;
        int size;

        sllSort(int size){
            this->size = size;
            arr = new int[size];

            input();
            shellSort();
        }

        void input(){
            for(int i = 0;i < size; i++){
                cout << "Enter " << i << "th element: ";
                cin >> arr[i];
            }
        }

        void print(){
            for(int i = 0;i < size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

        void shellSort(){
            for (int interval = size / 2; interval > 0; interval /= 2) {
                for (int i = interval; i < size; i += 1) {
                    int temp = arr[i];
                    int j;
                    for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                        arr[j] = arr[j - interval];
                    }
                    arr[j] = temp;
                }
            }

            cout << "Sorted list: ";
            print();
        }

        ~sllSort(){
            delete[] arr;
        }
};

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;

    sllSort myObj(size);

    return 0;
}