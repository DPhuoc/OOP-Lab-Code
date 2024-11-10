#include <bits/stdc++.h>

using namespace std;

class Donthuc {
    private: int bac;
    double heso;
    public: Donthuc(int n = 0, double h = 0): bac(n),
    heso(h) {}
    void xuat(int flag = 0) {
        if (flag == 1 && heso != 0) {
            cout << heso << "x^" << bac;
        } else if (bac == 0) {
            if (heso > 0) cout << " + " << heso;
            else if (heso < 0) cout << " - " << -heso;
        } else if (bac == 1) {
            if (heso > 0) cout << " + " << heso << "x";
            else if (heso < 0) cout << " - " << -heso << "x";
        } else if (heso > 0) {
            cout << " + " << heso << "x^" << bac;
        } else if (heso < 0) {
            cout << " - " << -heso << "x^" << bac;
        } else {
            return;
        }
    }
    friend Donthuc operator + (const Donthuc & lfs,
        const Donthuc & rhs) {
        return Donthuc(lfs.bac, lfs.heso + rhs.heso);
    }
    friend Donthuc operator - (const Donthuc & lfs,
        const Donthuc & rhs) {
        return Donthuc(lfs.bac, lfs.heso - rhs.heso);
    }
    double giatri(double x) {
        return heso * pow(x, bac);
    }
};
class Dathuc {
    private: int bac;
    vector < Donthuc > donthuc;
    public: Dathuc(int n = 0): bac(n) {}
    void nhap() {
        for (int i = bac; i >= 0; i--) {
            double h;
            cout << "Nhap he so bac " << i << ": ";
            cin >> h;
            donthuc.push_back(Donthuc(i, h));
        }
    }
    void xuat() {
        for (int i = 0; i <= bac; i++) {
            if (i == 0) donthuc[i].xuat(1);
            else
                donthuc[i].xuat();
        }
        cout << endl;
    }
    friend Dathuc operator + (const Dathuc & lfs,
        const Dathuc & rhs) {
        Dathuc res(max(lfs.bac, rhs.bac));
        for (int i = 0; i <= min(lfs.bac, rhs.bac); i++) {
            res.donthuc.push_back(lfs.donthuc[i] + rhs.donthuc[i]);
        }
        for (int i = min(lfs.bac, rhs.bac) + 1; i <= max(lfs.bac, rhs.bac); i++) {
            if (lfs.bac > rhs.bac) res.donthuc.push_back(lfs.donthuc[i]);
            else res.donthuc.push_back(rhs.donthuc[i]);
        }
        return res;
    }
    friend Dathuc operator - (const Dathuc & lfs,
        const Dathuc & rhs) {
        Dathuc res(max(lfs.bac, rhs.bac));
        for (int i = 0; i <= min(lfs.bac, rhs.bac); i++) {
            res.donthuc.push_back(lfs.donthuc[i] - rhs.donthuc[i]);
        }
        Donthuc tmp;
        for (int i = min(lfs.bac, rhs.bac) + 1; i <= max(lfs.bac, rhs.bac); i++) {
            if (lfs.bac > rhs.bac) res.donthuc.push_back(lfs.donthuc[i]);
            else res.donthuc.push_back(tmp - rhs.donthuc[i]);
        }
        return res;
    }
    double giatri(double x) {
        double res = 0;
        for (int i = 0; i <= bac; i++) {
            res += donthuc[i].giatri(x);
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Nhap bac cua da thuc 1: ";
    cin >> n;
    Dathuc dt1(n);
    dt1.nhap();
    cout << "Da thuc 1: " << endl;
    dt1.xuat();

    cout << "Nhap bac cua da thuc 2: ";
    cin >> n;
    Dathuc dt2(n);
    dt2.nhap();
    cout << "Da thuc 2: " << endl;
    dt2.xuat();

    Dathuc dt3 = dt1 + dt2;
    cout << "Tong 2 da thuc" << endl;
    dt3.xuat();

    Dathuc dt4 = dt1 - dt2;
    cout << "Hieu 2 da thuc" << endl;
    dt4.xuat();

    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Gia tri cua da thuc 1 tai x = " << x << " la: " << dt1.giatri(x) << endl;

    return 0;

}