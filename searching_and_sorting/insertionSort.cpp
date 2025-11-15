#include<iostream>
#include<math.h>
using namespace std;

class iSort {
    public: 
        int* arr;
        int size;

       iSort(int size){
            this->size = size;
            arr = new int[size];

            input();
            insertionSort();
        }

        void input(){
            for(int i = 0;i < size;i++){
                cout << "Enter " << i << " element: ";
                cin >> arr[i];
            }
        }

        void print(int* arr){
            for(int i = 0;i < size;i++){
                cout << arr[i] <<" ";
            }
            cout << "\n";
        }

        void insertionSort(){ 
            for (int step = 1; step < size; step++) {
                int key = arr[step];   
                int j = step - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
            print(arr);
        }

        ~iSort(){
            delete[] arr;
        }
};

int main(){
   int size;
   cout << "Enter size: ";
   cin >> size;

   iSort myObj(size);

   return 0;
}