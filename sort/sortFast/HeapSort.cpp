
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class HeapSort{
    private:
        void swap(int *a, int *b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        void getArrMaxHeap(vector<int> &arr,  int i, int n){
            int indexNode = i;
            int indexNodeLeft = 2*indexNode + 1,
                indexNodeRight = 2*indexNode + 2;
            if (indexNodeLeft < n && arr[indexNodeLeft] > arr[indexNode]){
                indexNode = indexNodeLeft;
            }
            if (indexNodeRight < n && arr[indexNodeRight] > arr[indexNode]){
                indexNode = indexNodeRight;
            }
            if (indexNode != i){
                swap(&arr[i], &arr[indexNode]);
                getArrMaxHeap(arr, indexNode, n);
            }
        }
    public:
        void sort(vector<int> &arr,  int n){
            for (int i = (n - 1)/2; i >= 0; i--){
                getArrMaxHeap(arr, i, n);
            }
            for (int i = n - 1; i > 0; i--){
                swap(&arr[0], &arr[i]);
                getArrMaxHeap(arr, 0, i);
            }
        }
};

int main(){

    vector<int> arr;
    // {6, 5, 3, 1, 8, 7, 2, 4};
    int n; 
    // 8;
    
    cout << "Enter the number of elements: "; cin >> n;
    cout << "Enter the elements: "; 
    for (int i = 0; i < n; i++){ 
        int temp; 
        cin >> temp; 
        arr.push_back(temp); 
    }

    cout << "Array before sorting: ";
    printArray(arr, n);

    HeapSort hs;
    hs.sort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}