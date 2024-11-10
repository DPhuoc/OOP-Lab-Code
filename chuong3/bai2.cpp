#include <iostream>
#include <cmath>  
using namespace std;

class Circle {
private:
    float x, y;
    float radius;

public:
    Circle() {
        x = 0; y = 0; radius = 0;
    }

    Circle(float x, float y, float r) {
        x = x; y = y; radius = r;
    }

    void input() {
        cout << "Nhập toạ độ X của tâm đường tròn: "; cin >> x;
        cout << "Nhạp toạ độ Y của tâm đường tròn: "; cin >> y;
        cout << "Nhập bán kính của đường tròn: "; cin >> radius;
    }

    float perimeter() {
        return 2 * M_PI * radius;
    }

    float area() {
        return M_PI * radius * radius;
    }

    void output() {
        cout << "Đường tròn tâm: (" << x << ', ' << y << "), bán kính: " << radius << endl;
        cout << "Chu vi của đường tròn là: " << perimeter() << endl;
        cout << "Diện tích của đường tròn là: " << area() << endl;
    }

};

int main() {
    Circle c;
    c.input();
    c.output();
}