#include "GiaSuc.h"

class De : public GiaSuc {
public:
    De();
    De(long long soluong);

    long long sinhCon() const override;
    long long choSua() const override;
};