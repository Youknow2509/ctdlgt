
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

class Line{
    Point s, e;
public:
    Line(){}
    Line(Point a, Point b){
        s = a;
        e = b;
    }
    double dodai(){
        return sqrt((s.get_x() - e.get_x())*(s.get_x() - e.get_x()) + (s.get_y() - e.get_y())*(s.get_y() - e.get_y()));
    }

    bool ktr_diem_thuoc_dt(double x, double y){
        return ((x - s.get_x())/(e.get_x() - s.get_x()) - (y - s.get_y())/(e.get_y() - s.get_y()) == 0) 
                && ((x - s.get_x())*(e.get_x() - x) >= 0);
    }
    bool ktr_diem_thuoc_dt(Point A){
        return ((A.get_x() - s.get_x())/(e.get_x() - s.get_x()) - (A.get_y() - s.get_y())/(e.get_y() - s.get_y()) == 0)
                && ((A.get_x() - s.get_x())*(e.get_x() - A.get_x()) >= 0);
    }

    void inf(){
        cout << "Doan thang co dang: (x - " << s.get_x() << ")/" << (e.get_x() - s.get_x())<<" = (y - " << s.get_y() << ")/" << (e.get_y() - s.get_y()) << endl;
        cout << "Toa do hai diem dau mut: A(" << s.get_x() << ", " << s.get_y() <<") va B(" << e.get_x() << ", " << e.get_y() <<")."<< endl;
        cout << "Do dai doan thang la: " << dodai() << endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("screen/inp.txt", "r", stdin);
    freopen("screen/out.txt", "w", stdout);
    #endif

    double x, y;  cin >> x >> y; // 6 8
    Point A(x, y);
    A.show();
    cin >> x >> y; // 0 0
    Point B(x, y);
    B.show();
    Line S(A, B);
    cout << "Do dai doan thang S la: " << S.dodai() << endl;

    S.inf();

    Point C(3, 4);

    if (S.ktr_diem_thuoc_dt(C)){
        cout << "Diem C thuoc doan thang AB" << endl;
    } else {
        cout << "Diem C khong thuoc doan thang AB" << endl;
    }

    return 0;
}