// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSBound::LoadBinary, BSBound::CreateClone, BSBound::GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSBoundLoader, BSBoundLoader::Load, loaderA, loaderB: GUESS(low); names invented, Load is bound by address through bind-hints.json
// NiExtraData::LoadBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bound by address through bind-hints.json
// NiRTTI_BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bound by address through bind-hints.json
// Unit-local view of BSBound: carries the members and declarations the functions of this unit need, so the shared BSBound.h stays as it is.
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiExtraData.h"

// NiRTTI_BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the RTTI object at RVA 0x332e3a0 that GetRTTI addresses, bound by hint
extern const NiRTTI NiRTTI_BSBound;

// BSBoundLoader: GUESS(low); embedded twice at 0x18 and 0x24, 0xC bytes each (three floats, the center and the extents); Load is declared only and bound by address
// x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiPoint3 member names
class BSBoundLoader
{
public:
    void Load(NiStream& a_stream);

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(BSBoundLoader) == 0x0C, "BSBoundLoader size");

// NiExtraData_CopyMembers: GUESS(low); the base copy routine the image calls with (source, destination, cloning); bound by address through bind-hints.json
void NiExtraData_CopyMembers(NiExtraData* a_source, NiExtraData* a_dest, NiCloningProcess& a_cloning);

class BSBound : public NiExtraData
{
public:
    // CopyMembers: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); non-virtual, copies into a_dest
    void CopyMembers(BSBound* a_dest, NiCloningProcess& a_cloning);  // compared: 0xff1770
    bool IsEqual(NiObject* a_object) override;  // 1C, compared: 0xff1870
    virtual void LoadBinary(NiStream& a_stream);  // compared: 0xff17c0
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);  // compared: 0xff1760
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xff1b90

    // loaderA, loaderB: GUESS(low); the two embedded loaders the load pass calls, at 0x18 and 0x24
    BSBoundLoader loaderA;  // 18
    BSBoundLoader loaderB;  // 24
};
static_assert(sizeof(BSBound) == 0x30, "BSBound size");
