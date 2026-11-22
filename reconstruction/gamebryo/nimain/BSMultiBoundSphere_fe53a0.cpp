// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSMultiBoundSphere: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the local listing
// 0xfe53a0 BSMultiBoundSphere::IsEqual
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "BSMultiBoundSphere_fe53a0.h"

// IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
static bool CentersEqual(const BSMultiBoundSphere& a_lhs, const BSMultiBoundSphere& a_rhs)
{
    return a_lhs.centerX == a_rhs.centerX && a_lhs.centerY == a_rhs.centerY && a_lhs.centerZ == a_rhs.centerZ;
}

bool BSMultiBoundSphere::IsEqual(NiObject* a_object)
{
    bool equal = IsEqualBase(reinterpret_cast<NiObject*>(this), a_object);
    if (equal) {
        auto other = reinterpret_cast<BSMultiBoundSphere*>(a_object);
        equal = CentersEqual(*this, *other);
        equal &= radius == other->radius;
    }
    return equal;
}
