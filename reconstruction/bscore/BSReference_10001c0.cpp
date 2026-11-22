// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSReference: EXE_RTTI
// RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Code origin: original reconstruction from the local listing
// SPDX-License-Identifier: CC0-1.0
// 0x10001c0 BSReference::IsEqual
#include "BSReference_10001c0.h"
#include <cstring>
// RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t BSReference::RegisterStreamables() const
{
    return 0x1;
}

// IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
bool BSReference::IsEqual(NiObject* a_object)
{
    if (!IsEqualBase(reinterpret_cast<NiObject*>(this), a_object)) {
        return false;
    }
    auto other = reinterpret_cast<BSReference*>(a_object);
    if (!pName || !other->pName) {
        return false;
    }
    return _stricmp(pName, other->pName) == 0;
}
