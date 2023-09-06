
#include <bits/stdc++.h>

using namespace std;

class Date{
    int day, month, year;
    int so_ngay_trong_thang(int m, int y) {
        if (m == 2) { // Tháng 2 cuả năm nhuận có 29 ngày còn các năm khác có 28 ngày
            return check_nam_nhuan(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }
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
    bool check_nam_nhuan(int y){
        return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    }
    bool check(int d, int m, int y){
        return d > 0 && m > 0 && m <= 12 && d < so_ngay_trong_thang(m, y);
    }
    void updateDate(int d, int m, int y){
        if (check(d, m, y)){ // Ngày, tháng, năm nhập vào phải có trong thời gian thực
//
        } else {
            cout << "Error !!!" << endl;
        }
    }

    int so_ngay_cach_nhau(Date A){
//
    }
    int so_ngay_cach_nhau(int d, int m, int y){
//
    }
    void show(){
        cout << "Day: " << setw (2) << setfill('0') << day << ", month: " 
                << setw (2) << setfill('0') << month << ", year: "
                << year << endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("screen/inp.txt", "r", stdin);
    freopen("screen/out.txt", "w", stdout);
    #endif

    

    return 0;
}