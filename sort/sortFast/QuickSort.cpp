
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class QuickSort{
    private:
        void swap(int *a, int *b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        int getPivot(vector<int> &arr,  int s, int e){
            int key = arr[e];
            int res = s;
            for (int i = s; i < e; i++){
                if (arr[i] <= key){
                    swap(&arr[i], &arr[res]);
                    res++;
                }
            }
            swap(&arr[res], &arr[e]);
            return res;
        }
    public:
        void sort(vector<int> &arr,  int s, int e){
            if (s < e){
                int m = getPivot(arr, s, e);
                sort(arr, s, m - 1);
                sort(arr, m + 1, e);
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

    QuickSort qs;
    qs.sort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}