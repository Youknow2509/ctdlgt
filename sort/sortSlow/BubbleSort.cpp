
#include<bits/stdc++.h>
#include"../printArr.cpp"

using namespace std;

class BubbleSort{
    private:
        void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
    public:
        void sort(vector<int> &arr, int n){
            bool swapped = true;
            for (int i = 0; i < n; i++){                
                for (int j = 0; j < n - i - 1; j++){    
                    if (arr[j] > arr[j + 1]){           
                        swap(arr[j], arr[j + 1]);       
                        swapped = false;              
                    }
                }
                if (swapped) {
                    break;
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

    BubbleSort bs;
    bs.sort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}