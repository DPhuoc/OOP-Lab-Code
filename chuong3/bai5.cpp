#include <iostream>
#include <string>
using namespace std;

class cHocSinh {
private:
    string ID;
    string Name;
    string Gender;
    int Year;
    float Avg;

public:
    cHocSinh() {}

    void nhapThongTin() {
        cout << "Nhập mã học sinh: "; cin >> ID;
        cin.ignore(); 
        cout << "Nhập họ tên: "; getline(cin, Name);
        cout << "Nhập giới tính: "; getline(cin, Gender);
        cout << "Nhập năm sinh: "; cin >> Year;
        cout << "Nhập điểm trung bình: "; cin >> Avg;
    }

    float getAVG() {
        return Avg;
    }

    float getYear() {
        return Year;
    }

    int calAge(int now) {
        return now - Year;
    }
};

int main() {
    cHocSinh hs1, hs2;

    cout << "Nhập thông tin học sinh 1:" << endl;
    hs1.nhapThongTin(); cout << endl;

    cout << "Nhập thông tin học sinh 2:" << endl;
    hs2.nhapThongTin(); cout << endl;

    cout << "So sánh điểm trung bình: " << endl;
    cout << (hs1.getAVG() == hs2.getAVG() ? "Cả hai học sinh có điểm trung bình bằng nhau." 
          : (hs1.getAVG() > hs2.getAVG() ? "Học sinh 1 có điểm trung bình cao hơn." 
          : "Học sinh 2 có điểm trung bình cao hơn.")) << endl;

    cout << "So sánh tuổi: " << endl;
    cout << (hs1.calAge(2024) == hs2.calAge(2024) ? "Cả hai học sinh bằng tuổi nhau."
          : (hs1.calAge(2024) < hs2.calAge(2024) ? "Học sinh 1 trẻ hơn."
          : "Học sinh 2 trẻ hơn.")) << endl;
}