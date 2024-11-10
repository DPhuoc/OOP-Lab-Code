#ifndef MATRAN_H
#define MATRAN_H

#include <iostream>
#include <vector>

class MaTran {
private:
    int m, n;          
    std::vector<std::vector<int>> data; 

public:
    MaTran(int m = 2, int n = 2);      
    void nhap();                     
    void xuat() const;              
    void taoNgauNhien();              

    MaTran operator+(const MaTran &mt) const;
    MaTran operator-(const MaTran &mt) const;
    MaTran operator*(const MaTran &mt) const; 

    bool kichThuocHopLe(const MaTran &mt) const; 

    friend std::ostream& operator<<(std::ostream &out, const MaTran &mt); 
};

#endif