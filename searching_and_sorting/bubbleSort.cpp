#include<iostream>
using namespace std;

class bSort{
    public:
        int* arr;
        int size;

        bSort(int size){
            this->size = size;
            arr = new int[size];

            input();
            bubbleSort();
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

        void bubbleSort(){ 
            for (int step = 0; step < size - 1; step++) {
                for (int j = 0; j < size - step - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            print(arr);
        }

        ~bSort(){
            delete[] arr;
        }
};

int main(){
   int size;
   cout << "Enter size: ";
   cin >> size;

   bSort myObj(size);

   return 0;
}