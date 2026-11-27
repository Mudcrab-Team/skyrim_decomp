// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBound::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfcd7d0 BSMultiBound::IsEqual
#include "BSMultiBound_fcd7d0.h"

// Compare two bounds by shape pointer and stored identifier.
bool BSMultiBound::IsEqual(NiObject* a_object)
{
    // NOTE: original calls NiObject::IsEqual without checking its return value.
    NiObject::IsEqual(a_object);
    BSMultiBound* other = static_cast<BSMultiBound*>(a_object);
    if (data == other->data && unk10 == other->unk10) {
        return true;
    }
    return false;
}
