#ifndef DONTHUC_H
#define DONTHUC_H

class DonThuc {
private:
    double heSo; //
    int bac;

public:
    DonThuc(double h = 0.0, int b = 0); 
    double tinhGiaTri(double x);    
    int layBac() const;                 
    double layHeSo() const;         
    void ganHeSo(double h);        
    void ganBac(int b);            

    friend std::ostream& operator<<(std::ostream &out, const DonThuc &d);
};

#endif