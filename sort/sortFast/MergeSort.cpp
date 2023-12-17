
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class MergeSort{
    private:
        void mergesort(vector<int> &arr, int s, int m, int e){
            vector<int> res = arr;
            int i = s, j = m + 1;
            int index = s;
            while (i <= m && j <= e){
                if (arr[i] > arr[j]){
                    res[index] = arr[j];
                    j++;
                } else {
                    res[index] = arr[i];
                    i++;
                }
                index++;
            }
            while (i <= m){
                res[index] = arr[i];
                i++;
                index++;
            }
            while (j <= e){
                res[index] = arr[j];
                j++;
                index++;
            }
            arr = res;
        }
    public:
        void sort(vector<int> &arr, int s, int e){
            if (s < e){
                int m = (s + e)/2;
                sort(arr, s, m);
                sort(arr, m + 1, e);
                mergesort(arr, s, m, e);
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

    MergeSort ms;
    ms.sort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}