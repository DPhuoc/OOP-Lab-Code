#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string Name;
    float Math;
    float Literature;

public:
    Student() {
        Name = "";
        Math = 0;
        Literature = 0;
    }

    Student(string name, float math, float literature) {
        Name = name;
        Math = math;
        Literature = literature;
    }

    void input() {
        cout << "Nhập họ tên: "; getline(cin, Name);
        cout << "Nhập điểm toán: "; cin >> Math;
        cout << "Nhập điểm văn: "; cin >> Literature;
    }

    float AVG() {
        return (Math + Literature) / 2;
    }

    string ranking() {
        float avg = AVG();
        if (avg >= 8.0) return "Giỏi";
        if (avg >= 6.5) return "Khá";
        if (avg >= 5.0) return "Trung bình";
        return "Yếu";
    }

    void output() {
        cout << "\nHọ tên: " << Name << endl;
        cout << "Điểm Toán: " << Math << endl;
        cout << "Điểm Văn: " << Literature << endl;
        cout << "Điểm trung bình: " << AVG() << endl;
        cout << "Xếp loại: " << ranking() << endl;
    }
};

int main() {
    Student st;
    st.input();
    st.output();
}