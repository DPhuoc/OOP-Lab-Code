#include <iostream>
#include <string>
using namespace std;

class HocSinh {
private:
    string ID;
    string NAME;
    string GENDER;
    float Math;
    float Physic;
    float Chemistry ;

public:
    void input() {
        cout << "Nhập mã học sinh: "; getline(cin, ID);
        cout << "Nhập họ tên: "; getline(cin, NAME);
        cout << "Nhập giới tính: "; getline(cin, GENDER);
        cout << "Nhập điểm toán: "; cin >> Math;
        cout << "Nhập điểm lý: "; cin >> Physic;
        cout << "Nhập điểm hóa: "; cin >> Chemistry ;
    }

    float averageCal() const {
        return (Math + Physic + Chemistry ) / 3;
    }

    void output() const {
        cout << "===== Thông tin học sinh =====" << endl;
        cout << "Mã học sinh: " << ID << endl;
        cout << "Họ tên: " << NAME << endl;
        cout << "Giới tính: " << GENDER << endl;
        cout << "Điểm Toán: " << Math << endl;
        cout << "Điểm Lý: " << Physic << endl;
        cout << "Điểm Hóa: " << Chemistry  << endl;
        cout << "Điểm trung bình: " << averageCal() << endl;
    }
};

int main() {
    HocSinh hs;

    cout << "Nhập thông tin học sinh:\n";
    hs.input();
    
    cout << "\nThông tin chi tiết học sinh:\n";
    hs.output();

    return 0;
}