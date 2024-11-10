#ifndef DATHUC_H
#define DATHUC_H

#include "donthuc.h"
#include <vector>

class DaThuc {
private:
    std::vector<DonThuc> cacDonThuc; 

public:
    DaThuc();                          
    DaThuc(int bac);                   
    void nhap();                            
    void xuat();                            
    double tinhGiaTri(double x);              
    DaThuc operator+(const DaThuc &dt);        
    DaThuc operator-(const DaThuc &dt);     

    friend std::ostream& operator<<(std::ostream &out, const DaThuc &dt); 
    friend std::istream& operator>>(std::istream &in, DaThuc &dt);      
};

#endif