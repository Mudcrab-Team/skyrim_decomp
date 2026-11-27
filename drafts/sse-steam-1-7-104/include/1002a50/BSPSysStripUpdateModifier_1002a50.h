// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fUpdateDeltaTime: SYMBOLS(fo4-pdb)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the observed prefix is represented.
// unknown08: GUESS(low); unrepresented base storage.

#pragma once
#include <cstddef>
class NiObject;
class NiPSysModifier
{
public:
    virtual bool IsEqual(NiObject* object);
    unsigned char unknown08[0x28];
};
class BSPSysStripUpdateModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object) override;
    float fUpdateDeltaTime;
};
static_assert(offsetof(BSPSysStripUpdateModifier, fUpdateDeltaTime) == 0x30, "update interval offset");
