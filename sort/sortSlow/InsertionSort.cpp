
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class InsertionSort{
    public:
        void sort(vector<int> &arr, int n){
            for (int i = 1; i < n; i++){
                int j = i - 1;
                int key = arr[i];
                while (j >= 0 && key <= arr[j]){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
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

    InsertionSort   is;
    is.sort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}