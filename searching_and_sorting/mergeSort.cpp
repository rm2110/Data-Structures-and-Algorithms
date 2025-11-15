#include<iostream>
#include<math.h>
using namespace std;

class Msort{
    public:
        int size;
        int start;
        int end;
        int* arr;

        Msort(int size, int start, int end){
            this->size = size;
            this->start = start;
            this->end = end;
            arr = new int[size];
            input();
        }

        void input(){
            for(int i = 0; i < size;i++){
                cout << "Enter " << i << " element: ";
                cin >> arr[i];
            }
        }

        void merge(int start, int middle, int end){
            int LeftSize = middle - start + 1;
            int RightSize = end - middle;

            int* arrLeft = new int[LeftSize];
            int* arrRight = new int[RightSize];

            for(int i = 0; i < LeftSize;i++){
                arrLeft[i] = arr[start + i];
            }
            for(int j = 0; j < RightSize;j++){
                arrRight[j] = arr[middle + j + 1];
            }

            int leftIndex = 0, rightIndex = 0;
            int k = start;

            while(leftIndex < LeftSize && rightIndex < RightSize){
                if(arrLeft[leftIndex] <= arrRight[rightIndex]){
                    arr[k] = arrLeft[leftIndex];
                    leftIndex++;
                }
                else {
                    arr[k] = arrRight[rightIndex];
                    rightIndex++;
                }
                k++;
            }

            while (leftIndex < LeftSize) {
                arr[k] = arrLeft[leftIndex];
                leftIndex++;
                k++;
            }
            while (rightIndex < RightSize) {
                arr[k] = arrRight[rightIndex];
                rightIndex++;
                k++;
            }

            delete[] arrLeft;
            delete[] arrRight;
        }

        void mergeSort(int start, int end){
            if(start < end){
                int middle = (start + end) / 2;
                mergeSort(start, middle);
                mergeSort(middle + 1, end);
                merge(start, middle, end);
            }
        }

        void print(){
            for(int i = 0;i < size;i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

        ~Msort() {
            delete[] arr;
        }
};

int main(){
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    Msort obj(size, 0, size - 1);
    obj.mergeSort(0, size - 1);
    obj.print();

    return 0;
}