#include <iostream>
#include<algorithm>
using namespace std;

class Hsort {
public:
    int n;
    int* arr;

     Hsort(int n){
        this->n = n;
        arr = new int[n];
        input();
        heapSort();
    }

    void input(){
        for(int i = 0;i < n;i++){
            cout << "Enter " << i << "th element: ";
            cin >> arr[i];
        }
    }

    void heapify(int i,int n){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n){
            if(arr[left] > arr[largest]){
                largest = left;
            }
        }
        if(right < n){
            if(arr[right]>arr[largest]){
                largest = right;
            }
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest, n);
        }
    }
    
    void buildHeap(){
        for(int i = n / 2 - 1;i >= 0; i--){
            heapify(i, n);
        }
    }

    void heapSort(){
        buildHeap();
        
        for(int i = n - 1;i >= 0; i--){
            swap(arr[0], arr[i]);
            heapify(0, i);
        }
    }

    void display(){
        for(int i = 0;i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;

    Hsort obj(size);
    obj.display();

    return 0;
}