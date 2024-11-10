#include <bits/stdc++.h>
using namespace std;

class cArray {
private:
    int* arr;   
    int size;

public:
    cArray(int n) {
        size = n;
        arr = new int[size];
        srand(time(0));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() - INT_MAX / 2;
        }
    }

    ~cArray() {
        delete[] arr;
    }

    void output() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int findMaxNegative() {
        int res = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (res < arr[i] && arr[i] < 0) res = arr[i];
        }
        return res;
    }

    int countX(int x) {
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) cnt++;
        }
        return cnt;
    }

    bool checkDecr() {
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] <= arr[i]) return false;
        }
        return true;
    }

    void sortInc() {
        sort(arr, arr + size);
    }
};

int main() {
    cArray myArray(15);
    cout << "Mảng ban đầu: " << endl; myArray.output();

    int jne = myArray.findMaxNegative();

    if (jne == INT_MIN) cout << "Không có số âm trong mảng" << endl;
    else cout << "Số âm lớn nhất trong mảng: " << jne << endl;

    int x;
    cout << "Nhập số cần đếm số lần xuất hiện: "; cin >> x;
    cout << "Số lần xuất hiện của " << x << " trong mảng là: " << myArray.countX(x) << endl;

    if (myArray.checkDecr()) cout << "Mảng giảm dần" << endl;
    else cout << "Mảng không giảm dần" << endl;

    myArray.sortInc();
    cout << "Mảng sau khi sắp xếp tăng dần: " << endl;
    myArray.output();
}