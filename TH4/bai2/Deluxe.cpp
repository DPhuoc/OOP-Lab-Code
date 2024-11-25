#include "Deluxe.h"

Deluxe::Deluxe() : Phong() {}

Deluxe::Deluxe(long long sodem, long long dichvu, long long phucvu) :
    Phong(sodem, 750000, dichvu, phucvu) {}

// long long Deluxe::DoanhThu() const {
//     return Phong().DoanhThu();
// }
