// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf6e440 EulerFillLeaff6e440::FillDerivedVals
#include "EulerFillLeaff6e440_f6e440.h"

void EulerFillLeaff6e440::FillDerivedVals(EulerFillLeaff6e440* values, std::uint32_t, std::uint8_t)
{
    for (std::uint32_t axis = 0; axis < 3; ++axis) {
        if (values->keys[axis]) {
            gEulerFillFunctionsf6e440[values->types[axis]](values->keys[axis], values->counts[axis], values->strides[axis]);
        }
    }
}
