
#include <bits/stdc++.h>

using namespace std;

class Point{
    double x, y;
public:
    Point(){}
    Point(double a, double b){
        x = a;
        y = b;
    }
    void show(){
        cout << "Diem co toa do la: ("<< x <<", "<< y <<")." << endl;
    }
    double distance(Point A){
        return sqrt((x - A.x)*(x - A.x) + (y - A.y)*(y - A.y));
    }
    double distance(double a, double b){
        return sqrt((x - a)*(x - a) + (y - b)*(y - b));
    }
    double get_x(){
        return x;
    }
    double get_y(){
        return y;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("screen/inp.txt", "r", stdin);
    freopen("screen/out.txt", "w", stdout);
    #endif

    double x, y;  cin >> x >> y;
    Point A(x, y); // 3
    A.show();

    cout << "Khoang cach tu A den goc toa do la: " << A.distance(0, 0) << endl;

    cout << "Check: " << endl;
    Point O(0, 0);
    cout << "   Distance: " << A.distance(O) << endl;

    return 0;
}