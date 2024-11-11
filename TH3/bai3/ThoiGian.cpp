#include "ThoiGian.h"

// Khởi tạo giá trị mặc định 0 cho giờ, phút và giây
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Khởi tạo với giá trị đầu vào: giờ, phút và giây
// Input: Gio - giờ, Phut - phút, Giay - giây
// Output: không có
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

// Tính tổng số giây từ giá trị giờ, phút, giây hiện tại
// Input: không có
// Output: Tổng số giây từ giá trị hiện tại
int ThoiGian::TinhGiay() {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Chuyển đổi một giá trị giây thành giờ, phút, giây
// Input: Giay - tổng số giây cần chuyển đổi
// Output: không có
// Giải thuật: Tính giờ bằng cách chia tổng số giây cho 3600,
// sau đó lấy phần dư chia cho 60 để tìm phút, phần còn lại là giây.
void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    iPhut = (Giay % 3600) / 60;
    iGiay = Giay % 60;
}

// Cộng thêm một giá trị giây vào thời gian hiện tại
// Input: Giay - số giây cần cộng
// Output: Đối tượng ThoiGian mới với thời gian đã cộng thêm số giây
ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

// Trừ đi một giá trị giây từ thời gian hiện tại
// Input: Giay - số giây cần trừ
// Output: Đối tượng ThoiGian mới với thời gian đã trừ số giây
ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

// Cộng hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần cộng
// Output: Đối tượng ThoiGian mới là tổng của hai đối tượng
ThoiGian ThoiGian::operator+(ThoiGian a) {
    int totalSeconds = TinhGiay() + a.TinhGiay();
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

// Trừ một đối tượng ThoiGian từ đối tượng hiện tại
// Input: a - đối tượng ThoiGian cần trừ
// Output: Đối tượng ThoiGian mới là hiệu của hai đối tượng
ThoiGian ThoiGian::operator-(ThoiGian a) {
    int totalSeconds = TinhGiay() - a.TinhGiay();
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

// Tăng thời gian hiện tại thêm 1 giây (prefix increment)
// Input: không có
// Output: Đối tượng ThoiGian sau khi tăng thêm 1 giây
ThoiGian ThoiGian::operator++() {
    int totalSeconds = TinhGiay() + 1;
    TinhLaiGio(totalSeconds);
    return *this;
}

// Giảm thời gian hiện tại đi 1 giây (prefix decrement)
// Input: không có
// Output: Đối tượng ThoiGian sau khi giảm 1 giây
ThoiGian ThoiGian::operator--() {
    int totalSeconds = TinhGiay() - 1;
    TinhLaiGio(totalSeconds);
    return *this;
}

// So sánh bằng giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu hai thời gian bằng nhau, ngược lại false
bool ThoiGian::operator==(ThoiGian a) {
    return TinhGiay() == a.TinhGiay();
}

// So sánh không bằng giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu hai thời gian không bằng nhau, ngược lại false
bool ThoiGian::operator!=(ThoiGian a) {
    return TinhGiay() != a.TinhGiay();
}

// So sánh lớn hơn hoặc bằng giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu thời gian hiện tại lớn hơn hoặc bằng thời gian của a
bool ThoiGian::operator>=(ThoiGian a) {
    return TinhGiay() >= a.TinhGiay();
}

// So sánh nhỏ hơn hoặc bằng giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu thời gian hiện tại nhỏ hơn hoặc bằng thời gian của a
bool ThoiGian::operator<=(ThoiGian a) {
    return TinhGiay() <= a.TinhGiay();
}

// So sánh lớn hơn giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu thời gian hiện tại lớn hơn thời gian của a
bool ThoiGian::operator>(ThoiGian a) {
    return TinhGiay() > a.TinhGiay();
}

// So sánh nhỏ hơn giữa hai đối tượng ThoiGian
// Input: a - đối tượng ThoiGian cần so sánh
// Output: true nếu thời gian hiện tại nhỏ hơn thời gian của a
bool ThoiGian::operator<(ThoiGian a) {
    return TinhGiay() < a.TinhGiay();
}

// Hàm nhập từ luồng vào cho đối tượng ThoiGian
// Input: luồng vào và đối tượng ThoiGian cần nhập
// Output: luồng vào sau khi hoàn thành việc nhập
istream& operator>>(istream& in, ThoiGian& tg) {
    cout << "Nhap gio (hh mm ss): ";
    in >> tg.iGio >> tg.iPhut >> tg.iGiay;
    return in;
}

// Hàm xuất đối tượng ThoiGian ra luồng ra
// Input: luồng ra và đối tượng ThoiGian cần xuất
// Output: luồng ra sau khi hoàn thành việc xuất
ostream& operator<<(ostream& out, const ThoiGian& tg) {
    out << tg.iGio << ":" << tg.iPhut << ":" << tg.iGiay;
    return out;
}
