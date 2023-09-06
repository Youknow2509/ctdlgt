
#include <bits/stdc++.h>

using namespace std;

class Date{
    int day, month, year;
public:
    Date(){
        day = 1;
        month = 1;
        year = 1900;
    }
    Date(int d, int m, int y){
        if (check(d,  m, y)){
            day = d; month = m; year = y;
        } else {
            cout << "Du lieu nhap vao bi loi" << endl;
            Date();
        }
    }
    bool check(int d, int m, int y){
//
    }
    void show(){
//
    }
    void check_nam_nhuan(){
//
    }
    void updateDate(){
//
    }

    int so_ngay_cach_nhau(Date A){
//
    }
    int so_ngay_cach_nhau(int d, int m, int y){
//
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("screen/inp.txt", "r", stdin);
    freopen("screen/out.txt", "w", stdout);
    #endif

    

    return 0;
}