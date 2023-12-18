
#include<iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable{
    private:
        int size_arr;
        vector<list<int> > arr;
        int hash(int key){
            return key%size_arr;
        }
    public:
        HashTable(){
            size_arr = 1000;
            arr.resize(size_arr);
        }
        void insert(int data){
            int index = hash(data);
            arr[index].push_back(data);
        }
        bool search(int data){
            int index = hash(data);
            list<int>::iterator it;
            for (it = arr[index].begin(); it != arr[index].end(); it++){
                if (*it == data){
                    return true;
                }
            }
            return false;
        }
};

int main(){

    HashTable ht;
    
    // {6, 5, 3, 1, 8, 7, 2, 4};
    int n;
    // 8;
    
    cout << "Enter the number of elements: "; cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ht.insert(temp);
    }
    cout << "Enter the element find: ";
    int key; cin >> key;
    
    if (ht.search(key)){
        cout << "Array have " << key << endl;
    } else {
        cout << "Array don't have " << key << endl;
    }
    

    return 0;
}
