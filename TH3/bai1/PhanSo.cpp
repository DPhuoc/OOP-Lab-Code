#include "PhanSo.h"
#include <algorithm>

// Constructor mặc định khởi tạo phân số với iTu = 0 và iMau = 1.
PhanSo::PhanSo() : iTu(0), iMau(1) {}

// Constructor khởi tạo phân số với tử số và mẫu số tùy ý, sau đó rút gọn.
PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    simplify(); // Rút gọn phân số sau khi khởi tạo
}

// Hàm rút gọn phân số
// Input: Không có (sử dụng iTu và iMau của đối tượng hiện tại)
// Output: Tử số và mẫu số của phân số hiện tại được rút gọn
void PhanSo::simplify() {
    int gcd = __gcd(iTu, iMau); // Tìm ước chung lớn nhất của tử và mẫu
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) { // Đảm bảo mẫu luôn dương
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Hàm chuyển đổi số thực thành phân số với độ chính xác 2 chữ số thập phân
// Input: `real` là số thực
// Output: Phân số biểu diễn giá trị của `real`
PhanSo doubleToFraction(double real) {
    int tu = static_cast<int>(real * 100); // Nhân với 100 để làm tròn 2 chữ số thập phân
    int mau = 100;
    return PhanSo(tu, mau); // Tạo phân số với tử và mẫu
}

// Phép cộng hai phân số
// Input: Phân số `other`
// Output: Phân số kết quả của phép cộng
PhanSo PhanSo::operator+(const PhanSo& other) {
    int Tu = iTu * other.iMau + other.iTu * iMau; // Tính tử số mới
    int Mau = iMau * other.iMau; // Tính mẫu số mới
    return PhanSo(Tu, Mau); // Trả về phân số kết quả
}

// Phép trừ hai phân số
// Input: Phân số `other`
// Output: Phân số kết quả của phép trừ
PhanSo PhanSo::operator-(const PhanSo& other) {
    int Tu = iTu * other.iMau - other.iTu * iMau; // Tính tử số mới
    int Mau = iMau * other.iMau; // Tính mẫu số mới
    return PhanSo(Tu, Mau); // Trả về phân số kết quả
}

// Phép nhân hai phân số
// Input: Phân số `other`
// Output: Phân số kết quả của phép nhân
PhanSo PhanSo::operator*(const PhanSo& other) {
    int Tu = iTu * other.iTu; // Nhân tử số
    int Mau = iMau * other.iMau; // Nhân mẫu số
    return PhanSo(Tu, Mau); // Trả về phân số kết quả
}

// Phép chia hai phân số
// Input: Phân số `other`
// Output: Phân số kết quả của phép chia
PhanSo PhanSo::operator/(const PhanSo& other) {
    int Tu = iTu * other.iMau; // Tử số mới
    int Mau = iMau * other.iTu; // Mẫu số mới
    return PhanSo(Tu, Mau); // Trả về phân số kết quả
}

// So sánh bằng hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu hai phân số bằng nhau, `false` nếu ngược lại
bool PhanSo::operator==(const PhanSo& other) {
    return iTu * other.iMau == iMau * other.iTu; // So sánh tích chéo
}

// So sánh khác nhau hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu hai phân số khác nhau, `false` nếu bằng nhau
bool PhanSo::operator!=(const PhanSo& other) {
    return !(*this == other); // Ngược lại với phép so sánh ==
}

// So sánh lớn hơn hoặc bằng hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu phân số hiện tại lớn hơn hoặc bằng `other`
bool PhanSo::operator>=(const PhanSo& other) {
    return iTu * other.iMau >= iMau * other.iTu; // So sánh tích chéo
}

// So sánh nhỏ hơn hoặc bằng hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu phân số hiện tại nhỏ hơn hoặc bằng `other`
bool PhanSo::operator<=(const PhanSo& other) {
    return iTu * other.iMau <= iMau * other.iTu; // So sánh tích chéo
}

// So sánh lớn hơn giữa hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu phân số hiện tại lớn hơn `other`
bool PhanSo::operator>(const PhanSo& other) {
    return iTu * other.iMau > iMau * other.iTu; // So sánh tích chéo
}

// So sánh nhỏ hơn giữa hai phân số
// Input: Phân số `other`
// Output: Trả về `true` nếu phân số hiện tại nhỏ hơn `other`
bool PhanSo::operator<(const PhanSo& other) {
    return iTu * other.iMau < iMau * other.iTu; // So sánh tích chéo
}

// Phép cộng phân số với số thực
// Input: Số thực `real`
// Output: Phân số kết quả của phép cộng với số thực
PhanSo PhanSo::operator+(double real) {
    PhanSo realFraction = doubleToFraction(real); // Chuyển đổi `real` thành phân số
    return *this + realFraction; // Cộng hai phân số
}

// Phép trừ phân số với số thực
// Input: Số thực `real`
// Output: Phân số kết quả của phép trừ với số thực
PhanSo PhanSo::operator-(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this - realFraction;
}

// Phép nhân phân số với số thực
// Input: Số thực `real`
// Output: Phân số kết quả của phép nhân với số thực
PhanSo PhanSo::operator*(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this * realFraction;
}

// Phép chia phân số với số thực
// Input: Số thực `real`
// Output: Phân số kết quả của phép chia với số thực
PhanSo PhanSo::operator/(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this / realFraction;
}

// Toán tử nhập phân số
// Input: `istream& in`, nhập tử và mẫu từ luồng vào
// Output: Đối tượng phân số với tử và mẫu đã nhập
istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau;
    ps.simplify(); // Rút gọn sau khi nhập
    return in;
}

// Toán tử xuất phân số
// Input: `ostream& out`
// Output: Xuất ra tử và mẫu của phân số theo định dạng "tử/mẫu"
ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.iMau == 1) out << ps.iTu; // Nếu mẫu là 1, chỉ in tử số
    else out << ps.iTu << "/" << ps.iMau;
    return out;
}
