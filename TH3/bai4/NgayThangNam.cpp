#include "NgayThangNam.h"

// Kiểm tra xem năm có phải là năm nhuận không
// Input: year (int) - năm cần kiểm tra
// Output: true nếu là năm nhuận, false nếu không
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Tính số ngày trong tháng của một năm cụ thể
// Input: month (int) - tháng cần kiểm tra, year (int) - năm cần kiểm tra
// Output: Số ngày trong tháng (int)
// Giải thuật: Dùng switch case để xác định số ngày của từng tháng,
// xử lý riêng cho tháng 2 với việc kiểm tra năm nhuận
int daysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

// Khởi tạo ngày mặc định (1/1/2000)
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

// Khởi tạo ngày với tham số cụ thể
// Input: ngay, thang, nam (int) - ngày, tháng, năm để khởi tạo
NgayThangNam::NgayThangNam(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) {}

// Tính số ngày từ ngày 1/1/1 đến ngày hiện tại
// Output: Tổng số ngày từ ngày 1/1/1 (int)
// Giải thuật: Sử dụng toán tử "-" để tính sự chênh lệch ngày giữa đối tượng hiện tại và ngày 1/1/1
int NgayThangNam::TinhNgay() {
    return *this - NgayThangNam(1, 1, 1);
}

// Cộng số ngày vào đối tượng ngày tháng năm
// Input: ngay (int) - số ngày cần cộng thêm
// Output: Đối tượng NgayThangNam với ngày mới
// Giải thuật: Tăng số ngày từng tháng, cập nhật tháng và năm khi cần thiết
NgayThangNam NgayThangNam::operator + (int ngay) const {
    NgayThangNam result = *this;
    while (ngay > 0) {
        int dayMonth = daysInMonth(result.iThang, result.iNam);
        if (result.iNgay + ngay <= dayMonth) {
            result.iNgay += ngay;
            break;
        } else {
            ngay -= (dayMonth - result.iNgay + 1);
            result.iNgay = 1;
            if (++result.iThang > 12) {
                result.iThang = 1;
                ++result.iNam;
            }
        }
    }
    return result;
}

// Trừ số ngày từ đối tượng ngày tháng năm
// Input: ngay (int) - số ngày cần trừ
// Output: Đối tượng NgayThangNam với ngày mới
// Giải thuật: Giảm số ngày từng tháng, cập nhật tháng và năm khi cần thiết
NgayThangNam NgayThangNam::operator - (int ngay) const {
    NgayThangNam result = *this;
    while (ngay > 0) {
        if (result.iNgay > ngay) {
            result.iNgay -= ngay;
            break;
        } else {
            ngay -= result.iNgay;
            if (--result.iThang < 1) {
                result.iThang = 12;
                --result.iNam;
            }
            result.iNgay = daysInMonth(result.iThang, result.iNam);
        }
    }
    return result;
}

// Tính số ngày chênh lệch giữa hai ngày
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: Số ngày chênh lệch (int)
// Giải thuật: Tính tổng số ngày từ ngày 1/1/1 đến ngày hiện tại và ngày khác, sau đó lấy hiệu
int NgayThangNam::operator-(const NgayThangNam& other) const {
    int days1 = iNgay, days2 = other.iNgay;

    for (int y = 0; y < iNam; y++) days1 += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < iThang; m++) days1 += daysInMonth(m, iNam);

    for (int y = 0; y < other.iNam; y++) days2 += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < other.iThang; m++) days2 += daysInMonth(m, other.iNam);

    return days1 - days2;
}

// So sánh hai ngày có bằng nhau hay không
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu bằng, false nếu không bằng
bool NgayThangNam::operator == (const NgayThangNam& other) const {
    return (iNgay == other.iNgay && iThang == other.iThang && iNam == other.iNam);
}

// So sánh hai ngày có khác nhau hay không
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu khác, false nếu bằng
bool NgayThangNam::operator != (const NgayThangNam& other) const {
    return !(*this == other);
}

// Tăng ngày lên 1
// Output: Đối tượng ngày tháng năm sau khi tăng
// Giải thuật: Sử dụng toán tử "+" để tăng thêm 1 ngày
NgayThangNam& NgayThangNam::operator ++ () {
    *this = *this + 1;
    return *this;
}

// Tăng ngày lên 1 (dạng hậu tố)
// Output: Đối tượng ngày tháng năm trước khi tăng
NgayThangNam NgayThangNam::operator ++ (int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}

// Giảm ngày đi 1
// Output: Đối tượng ngày tháng năm sau khi giảm
// Giải thuật: Sử dụng toán tử "-" để giảm đi 1 ngày
NgayThangNam& NgayThangNam::operator -- () {
    *this = *this - 1;
    return *this;
}

// Giảm ngày đi 1 (dạng hậu tố)
// Output: Đối tượng ngày tháng năm trước khi giảm
NgayThangNam NgayThangNam::operator -- (int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

// So sánh ngày hiện tại lớn hơn ngày khác hay không
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu lớn hơn, false nếu không
bool NgayThangNam::operator > (const NgayThangNam& other) const {
    if (iNam > other.iNam) return true;
    if (iNam == other.iNam && iThang > other.iThang) return true;
    return (iNam == other.iNam && iThang == other.iThang && iNgay > other.iNgay);
}

// So sánh ngày hiện tại lớn hơn hoặc bằng ngày khác
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu lớn hơn hoặc bằng, false nếu không
bool NgayThangNam::operator >= (const NgayThangNam& other) const {
    return (*this > other) || (*this == other);
}

// So sánh ngày hiện tại nhỏ hơn hoặc bằng ngày khác
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu nhỏ hơn hoặc bằng, false nếu không
bool NgayThangNam::operator <= (const NgayThangNam& other) const {
    return (*this < other) || (*this == other);
}

// So sánh ngày hiện tại nhỏ hơn ngày khác
// Input: other (NgayThangNam) - đối tượng ngày cần so sánh
// Output: true nếu nhỏ hơn, false nếu không
bool NgayThangNam::operator < (const NgayThangNam& other) const {
    return !(*this >= other);
}

// Nhập dữ liệu cho đối tượng NgayThangNam
// Input: is (istream) - luồng nhập, date (NgayThangNam) - đối tượng để gán dữ liệu
// Output: Luồng nhập (istream) để chuỗi lệnh tiếp theo có thể tiếp tục nhập liệu
std::istream& operator >> (std::istream& is, NgayThangNam& date) {
    is >> date.iNgay >> date.iThang >> date.iNam;
    return is;
}

// Xuất dữ liệu của đối tượng NgayThangNam
// Input: os (ostream) - luồng xuất, date (NgayThangNam) - đối tượng để xuất dữ liệu
// Output: Luồng xuất (ostream) để chuỗi lệnh tiếp theo có thể tiếp tục xuất dữ liệu
std::ostream& operator << (std::ostream& os, const NgayThangNam& date) {
    os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
    return os;
}
