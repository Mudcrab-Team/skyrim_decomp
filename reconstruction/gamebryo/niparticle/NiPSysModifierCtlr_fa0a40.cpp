// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// SPDX-License-Identifier: CC0-1.0
// IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifierCtlr: EXE_RTTI
// 0xfa0a40 NiPSysModifierCtlr::IsEqual
#include "NiPSysModifierCtlr_fa0a40.h"

bool NiPSysModifierCtlr::IsEqual(NiObject* a_object)
{
    if (!IsEqualBase(this, a_object)) {
        return false;
    }
    auto other = static_cast<NiPSysModifierCtlr*>(a_object);
    if (modifier) {
        if (!other->modifier || !modifier->IsEqual(other->modifier)) {
            return false;
        }
    } else if (other->modifier) {
        return false;
    }
    if (member != other->member) {
        return false;
    }
    return true;
}
