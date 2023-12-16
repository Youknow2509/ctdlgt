
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class SelecionSort{
    private:
        void swap(int *a, int *b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
    public:
        void sort(vector<int> &arr, int n){
            for (int i = 0; i < n - 1; i++){
                for (int j = i + 1; j < n; j++){
                    if (arr[i] > arr[j]){
                        swap(&arr[i], &arr[j]);
                    }
                }
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

    SelecionSort ss;
    ss.sort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}