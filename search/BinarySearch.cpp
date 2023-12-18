
#include<bits/stdc++.h>

using namespace std;

class BinarySearch{
    public:
        bool search(vector<int> arr, int n, int key){
            int s = 0, e = n - 1;
            while (s < e){
                int m = (s + e)/2;
                if (arr[m] > key){
                    e = m - 1;
                } else if (arr[m] < key){
                    s = m + 1;
                } else {
                    return true;
                }
            }
            
            return false;
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
    cout << "Enter the element find: "; 
    int key; cin >> key;
    BinarySearch bs;

    if  (bs.search(arr, n, key)){
        cout << "Array have " << key << endl;
    } else {
        cout << "Array don't have " << key << endl;
    }

    return 0;
}