#include "GiaSuc.h"

class Cuu : public GiaSuc {
public:
    Cuu();
    Cuu(long long soluong);

    long long sinhCon() const override;
    long long choSua() const override;
};