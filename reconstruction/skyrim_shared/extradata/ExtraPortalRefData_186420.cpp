// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x186420 ExtraPortalRefData::IsNotEqual
// Adapted bodies: none
#include "ExtraPortalRefData_186420.h"

bool ExtraPortalRefData::IsNotEqual(const BSExtraData* a_rhs) const
{
    const ExtraPortalRefData* rhs = reinterpret_cast<const ExtraPortalRefData*>(a_rhs);
    const PortalLinkedRefData* lhsData = data;
    const PortalLinkedRefData* rhsData = rhs->data;
    if (!lhsData && !rhsData)
    {
        return false;
    }
    if (!lhsData || !rhsData)
    {
        return true;
    }
    for (int i = 0; i < 2; ++i)
    {
        if (lhsData->linkedRefs[i] != rhsData->linkedRefs[i])
        {
            return true;
        }
    }
    return false;
}
