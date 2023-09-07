
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
    long long so_ngay(int d, int m, int y){
        long long res = 0;
        for (int i = 1990; i <= y; i++){
            res += check_nam_nhuan(i) ? 366 : 365;
        }
        for (int i = 1; i <= m; i++){
            res += so_ngay_trong_thang(i, y);
        }
        res += d;
        return res;
    }
    void chuanhoangaythang() {
        while (day > so_ngay_trong_thang(month, year)) {
            day -= so_ngay_trong_thang(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
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
    int get_day(){return day;}
    int get_month(){return month;}
    int get_year(){return year;}
    bool check_nam_nhuan(int y){
        return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    }
    bool check(int d, int m, int y){
        return d > 0 && m > 0 && m <= 12 && d < so_ngay_trong_thang(m, y);
    }
    void updateDate(int d, int m, int y){
        if (check(day + d, month + m, year + y)) {
            day += d;
            month += m;
            year += y;
            chuanhoangaythang();
        } else {
            cout << "Ngày tháng không hợp lệ sau khi cập nhật." << endl;
        }
    }

    int so_ngay_cach_nhau(Date A){
        return abs(so_ngay(day, month, year) - so_ngay(A.get_day(), A.get_month(), A.get_year()));
    }
    int so_ngay_cach_nhau(int d, int m, int y){
        return abs(so_ngay(day, month, year) - so_ngay(d, m,  y));
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