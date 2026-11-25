// Near miss: 72.31% | register-schedule
// Source exposure: mixed
// 0x1002a50 BSPSysStripUpdateModifier::IsEqual
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fUpdateDeltaTime: SYMBOLS(fo4-pdb)
#include "BSPSysStripUpdateModifier_1002a50.h"

bool BSPSysStripUpdateModifier::IsEqual(NiObject* object)
{
    if (!NiPSysModifier::IsEqual(object))
        return false;
    auto* other = reinterpret_cast<BSPSysStripUpdateModifier*>(object);
    if (fUpdateDeltaTime != other->fUpdateDeltaTime)
        return false;
    return true;
}
