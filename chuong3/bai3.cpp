#include <iostream>
#include <cmath> 
#include <string>
using namespace std;

class Point {
private:
    float x, y;

public:
    Point() {
        x = 0; y = 0;
    }

    Point(float x, float y) {
        x = x; y = y;
    }

    void input() {
        cout << "Nhập toạ độ X: "; cin >> x;
        cout << "Nhập toạ độ Y: "; cin >> y;
    }

    string output() {
        return "(" + to_string(x) + ", " + to_string(x) + ")";
    }

    float distance(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main() {
    Point p1, p2;

    cout << "Nhập tọa độ điểm thứ nhất:\n"; p1.input();
    cout << "Nhập tọa độ điểm thứ hai:\n"; p2.input();
    cout << "Khoảng cách giữa điểm " << p1.output() << " và " << p2.output() << " là: " << p1.distance(p2) << endl;
}