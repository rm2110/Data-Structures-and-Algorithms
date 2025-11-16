#include<iostream>
using namespace std;

class sSort{
    public:
        int* arr;
        int size;

        sSort(int size){
            this->size = size;
            arr = new int[size];

            input();
            selectionSort();
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

        void selectionSort(){
            for (int step = 0; step < size - 1; step++) {
                int minIndex = step;
                for (int i = step + 1; i < size; i++) {
                    if (arr[i] < arr[minIndex])
                        minIndex = i;
                    }
                    int temp = arr[minIndex];
                    arr[minIndex] = arr[step];
                    arr[step] = temp;
                }
    
            cout << "Sorted list: ";
            print();
        }

        ~sSort(){
            delete[] arr;
        }
};

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;

    sSort myObj(size);

    return 0;
}