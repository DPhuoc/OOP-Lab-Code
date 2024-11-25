#include "Phong.h"
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    Deluxe a(5, 200000, 50000); 
    Deluxe b(3, 150000, 30000);  
    Premium c(4, 100000);    
    Premium d(2, 50000);      
    Business e(6); 

    long long dtDeluxe = a.DoanhThu() + b.DoanhThu();
    long long dtPremium = c.DoanhThu() + d.DoanhThu();
    long long dtBusiness = e.DoanhThu();

    long long maxDT = max({dtDeluxe, dtPremium, dtBusiness});
    if (maxDT == dtDeluxe) cout << "Doanh thu cua phong Deluxe cao nhat: " << maxDT << endl;
    if (maxDT == dtPremium) cout << "Doanh thu cua phong Premium cao nhat: " << maxDT << endl;
    if (maxDT == dtBusiness) cout << "Doanh thu cua phong Business cao nhat: " << maxDT << endl;
}