// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf76750 BasisEqualLeaff76750::IsEqual
#include "BasisEqualLeaff76750_f76750.h"

bool BasisEqualLeaff76750::IsEqual(BasisEqualBase* other)
{
    if (!BasisEqualBase::IsEqual(other)) {
        return false;
    }
    const auto* basisData = static_cast<const BasisEqualLeaff76750*>(other);
    return basisData->basis.count == basis.count;
}
