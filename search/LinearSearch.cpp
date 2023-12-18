
#include<bits/stdc++.h>

using namespace std;

class LinearSearch{
    public:
        bool search(vector<int> arr, int n, int key){
            for (int i = 0; i < n; i++){
                if (arr[i] == key){
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
    LinearSearch ls;

    if (ls.search(arr, n, key)){
        cout << "Array have " << key << endl;
    } else {
        cout << "Array don't have " << key << endl;
    }

    return 0;
}