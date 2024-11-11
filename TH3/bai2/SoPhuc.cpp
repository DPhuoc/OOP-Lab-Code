#include "SoPhuc.h"

// Constructor mặc định khởi tạo số phức với phần thực và phần ảo là 0
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

// Constructor khởi tạo số phức với phần thực và phần ảo được truyền vào
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

// Phép cộng hai số phức
// Input: Số phức other để cộng với số phức hiện tại
// Output: Trả về một số phức mới với phần thực và phần ảo là tổng tương ứng của hai số phức
SoPhuc SoPhuc::operator+(const SoPhuc& other) {
    return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
}

// Phép trừ hai số phức
// Input: Số phức other để trừ khỏi số phức hiện tại
// Output: Trả về một số phức mới với phần thực và phần ảo là hiệu tương ứng của hai số phức
SoPhuc SoPhuc::operator-(const SoPhuc& other) {
    return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
}

// Phép nhân hai số phức
// Input: Số phức other để nhân với số phức hiện tại
// Output: Trả về một số phức mới là tích của hai số phức
SoPhuc SoPhuc::operator*(const SoPhuc& other) {
    return SoPhuc(dThuc * other.dThuc - dAo * other.dAo, dThuc * other.dAo + dAo * other.dThuc);
}

// Phép chia hai số phức
// Input: Số phức other để chia cho số phức hiện tại
// Output: Trả về một số phức mới là thương của hai số phức
SoPhuc SoPhuc::operator/(const SoPhuc& other) {
    double denominator = other.dThuc * other.dThuc + other.dAo * other.dAo;
    return SoPhuc((dThuc * other.dThuc + dAo * other.dAo) / denominator, (dAo * other.dThuc - dThuc * other.dAo) / denominator);
}

// So sánh bằng hai số phức
// Input: Số phức other để so sánh
// Output: Trả về true nếu hai số phức có phần thực và phần ảo bằng nhau, ngược lại trả về false
bool SoPhuc::operator==(const SoPhuc& other) {
    return (dThuc == other.dThuc) && (dAo == other.dAo);
}

// So sánh khác nhau giữa hai số phức
// Input: Số phức other để so sánh
// Output: Trả về true nếu hai số phức khác nhau, ngược lại trả về false
bool SoPhuc::operator!=(const SoPhuc& other) {
    return !(*this == other);
}

// Phép cộng số phức với một số thực
// Input: real - một số thực để cộng với số phức hiện tại
// Output: Trả về một số phức mới có phần thực là tổng của dThuc và real, phần ảo giữ nguyên
SoPhuc SoPhuc::operator+(double real) {
    return SoPhuc(dThuc + real, dAo);
}

// Phép trừ số phức với một số thực
// Input: real - một số thực để trừ khỏi số phức hiện tại
// Output: Trả về một số phức mới có phần thực là hiệu của dThuc và real, phần ảo giữ nguyên
SoPhuc SoPhuc::operator-(double real) {
    return SoPhuc(dThuc - real, dAo);
}

// Phép nhân số phức với một số thực
// Input: real - một số thực để nhân với số phức hiện tại
// Output: Trả về một số phức mới với cả phần thực và phần ảo nhân với real
SoPhuc SoPhuc::operator*(double real) {
    return SoPhuc(dThuc * real, dAo * real);
}

// Phép chia số phức cho một số thực
// Input: real - một số thực để chia cho số phức hiện tại
// Output: Trả về một số phức mới với cả phần thực và phần ảo chia cho real
SoPhuc SoPhuc::operator/(double real) {
    return SoPhuc(dThuc / real, dAo / real);
}

// Phép nhập số phức từ luồng đầu vào
// Input: Nhập giá trị cho phần thực và phần ảo từ người dùng
// Output: Trả về tham chiếu tới luồng đầu vào
istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.dThuc;
    cout << "Nhap phan ao: ";
    in >> sp.dAo;
    return in;
}

// Phép xuất số phức ra luồng đầu ra
// Input: Một số phức để xuất ra
// Output: Trả về tham chiếu tới luồng đầu ra
ostream& operator<<(ostream& out, const SoPhuc& sp) {
    out << sp.dThuc << " + " << sp.dAo << "i";
    return out;
}
