#include "GiaSuc.h"

class Bo : public GiaSuc {
public:
    Bo();
    Bo(long long soluong);

    long long sinhCon() const override;
    long long choSua() const override;
};