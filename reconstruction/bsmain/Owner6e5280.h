// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Code origin: original declarations with the cited sibling adaptations. Stamped as a twin of matched 0x1a4670 (bsmain/TES): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// NiPoint3, TESLandTexture, coord: GUESS(low)
// TESWorldSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function6e5280, Owner6e5280: GUESS(low) STANDIN
// GetLandMaterialType, GetLandTexture, worldSpace, unknown00: GUESS(low) STANDIN
#pragma once
#include "TES.h"

class Owner6e5280 {
public:
    TESWorldSpace* GetWorldSpace() const;
    bool Function1a2200(const Function1a2200Arg* a_arg, bool a_flag) const;
    void ResumeMasterFileLoads();
    void Function6e5280();
    TESLandTexture* GetLandTexture(const NiPoint3& coord);
    unsigned int GetLandMaterialType(const NiPoint3& coord);
    Owner6e5280* ScalarDeletingDestructor(unsigned a_flags);

    unsigned char unknown00[0x148];
    TESWorldSpace* worldSpace;
};
static_assert(offsetof(Owner6e5280, worldSpace) == 0x148, "Owner6e5280 worldspace offset");
