#include <bits/stdc++.h>
using namespace std;

class cBook {
    string maSach;     
    string tenSach;    
    int namXuatBan;   
    int tongSoTrang; 

public:
    void init(const string ma, const string ten, int nam, int soTrang) {
        maSach = ma;
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = soTrang;
    }

    void inputBook() {
        cout << "Nhập mã sách: "; cin >> maSach;
        cout << "Nhập tên sách: "; cin.ignore(); getline(cin, tenSach);
        cout << "Nhập năm xuất bản: "; cin >> namXuatBan;
        cout << "Nhập tổng số trang: "; cin >> tongSoTrang;
    }

    void xuat() {
        cout << "Mã sách: " << maSach << endl;
        cout << "Tên sách: " << tenSach << endl;
        cout << "Năm xuất bản: " << namXuatBan << endl;
        cout << "Tổng số trang: " << tongSoTrang << endl;
    }

    void capNhat(const string ten, int nam, int soTrang) {
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = soTrang;
    }

    int getNam() {
        return namXuatBan;
    }
};

class cListBook {
    cBook* arr;
    int size;

public:
    void inArr() {
        cout << "Nhập số lượng phần tử của mảng: "; cin >> size; 
        arr = new cBook[size];
        for (int i = 0; i < size; i++) {
            cout << "Nhập thông tin cuối sách thứ " << i << endl;
            arr[i].inputBook();
        }
    }

    void outArr() {
        for (int i = 0; i < size; i++) {
            cout << "Sách thứ " << i << ": " << endl;
            arr[i].xuat();
        }
    }

    void recentBook() {
        cBook recent = arr[0];
        for (int i = 1; i < size; i++) {
            if (recent.getNam() < arr[i].getNam()) recent = arr[i];
        }
        cout << "\nSách xuất bản gần đây nhất:\n";
        recent.xuat();
    }
};

string menu = 
    "\n======== MENU ========\n"
    "1. Nhập danh sách sách\n"
    "2. Xuất danh sách sách\n"
    "3. Tìm sách xuất bản gần đây nhất\n"
    "0. Thoát\n"
    "======================\n"
    "Nhập lựa chọn của bạn: ";

int main() {
    cListBook a;
    int choice;
    do {
        cout << menu;
        cin >> choice;

        switch(choice) {
            int x, min_le;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            case 1:
                a.inArr();
                break;
            case 2:
                a.outArr();
                break;
            case 3:
                a.recentBook();
                break;
        }
    } while(choice != 0);
}