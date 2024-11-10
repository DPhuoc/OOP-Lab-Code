#include <bits/stdc++.h>
using namespace std;

class cArray {
private:
    int* arr;   
    int size = 0;

public:
    void inArr() {
        cout << "Nhập số lượng phần tử của mảng: "; cin >> size; 
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            cout << "Nhập phần tử thứ " << i << ": ";
            cin >> arr[i];
        }
    }

    void outArr() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] <<' ';
        }
        cout << endl;
    }

    void genRan() {
        cout << "Nhập số lượng phần tử của mảng: "; cin >> size; 
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand() - INT_MAX / 2;
        }
    }

    int cntX(int x) {
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) cnt++;
        }
        return cnt;
    }

    bool checkInc() {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    int minEven() {
        int min_even = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0 && arr[i] < min_even) min_even = arr[i];
        }

        return min_even;
    }

    void sortInc() {
        sort(arr, arr + size);
    }
};

string menu = 
"\n======== MENU ========\n"
"1. Nhập mảng số nguyên\n"
"2. Xuất mảng số nguyên\n"
"3. Tạo mảng ngẫu nhiên\n"
"4. Đếm số lần xuất hiện của một số\n"
"5. Kiểm tra mảng có tăng dần\n"
"6. Tìm phần tử lẻ nhỏ nhất\n"
"7. Sắp xếp mảng theo thứ tự tăng dần\n"
"0. Thoát\n"
"======================\n"
"Nhập lựa chọn của bạn: ";

int main() {
    cArray a;
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
                a.genRan();
                break;
            case 4:
                cout << "Nhập số X: "; cin >> x;
                cout << "Số lần xuất hiện của " << x << " là: " << a.cntX(x) << endl;
                break;
            case 5:
                if (a.checkInc()) cout << "Mảng tăng dần\n";
                else cout << "Mảng không tăng dần\n";
                break;
            case 6: 
                min_le = a.minEven();
                if (min_le == INT_MAX) cout << "Mảng không tồn tại số lẻ\n";
                else cout << "Số lẻ nhỏ nhất trong mảng là: " << min_le << "\n";
                break;
            case 7:
                a.sortInc();
                break;
        }
    } while(choice != 0);
}