
#include <bits/stdc++.h>

using namespace std;

class Time{
    int h, m, s;
public:
    Time(){
        h = 0; m = 0; s = 0;
    }
    Time(int a, int b, int c){
        if (check(a, b, c)){
            h = a; m = b; s = c;
        } else {
            cout << "Thoi gian khong hop le !!!" << endl;
            Time();
        }
    }
    bool check(int h, int m, int s) {
        return (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59);
    }
    void updateTime(int a, int b, int c){
            h += a;
            m += b;
            s +=c;

            m += s/60;
            s = s%60;

            h += m/60;
            m = m%60;

            h = h%24;
    }
    void show(){
        cout << "Time: " << setw (2) << setfill('0') << h << " : " 
                << setw (2) << setfill('0') << m << " : "
                << setw (2) << setfill('0') << s << endl;
    }
};


int main(){

    #ifndef ONLINE_JUDGE
    freopen("screen/inp.txt", "r", stdin);
    freopen("screen/out.txt", "w", stdout);
    #endif

    Time A(25, 26, 99);
    cout << " _ " << endl;
    Time B(0, 0, 0);
    Time C(9, 30, 45);

    B.show();
    C.show();
    C.updateTime(10, 2, 20);
    C.show();

    return 0;
}