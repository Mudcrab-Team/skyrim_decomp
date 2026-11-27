// TESObjectLAND::GetSaveParentCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Code origin: declarations retained from the labelled existing local unit; new members inferred from the local listing.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesland_od_variant.cpp:928
// tools/check_origin.py reports no other body above its threshold.
// TESObjectLAND, TESObjectLAND::CreateDuplicateForm, ::SetAltered, ::parentCell, ::data, ::pad2C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a 4-byte block here, NG declares OBJ_LAND
// TESObjectLAND::unk38: GUESS(low); stands for queuedTextures and loadedData
// TESChildCell, TESChildCell::GetSaveParentCell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the TESForm base is needed
#pragma once
#include <cstdint>

namespace ReconstructedTESObjectLAND {


#include <cstdint>

#include "../forms/TESForm.h"

class TESObjectCELL : public TESForm {
};

class TESChildCell {
public:
    virtual TESObjectCELL* GetSaveParentCell();  // 01
};

class TESObjectLAND : public TESForm, public TESChildCell {
public:
    TESObjectCELL* GetSaveParentCell();

public:
    bool Function2b2600() const;

public:
    TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;  // 09
    void     SetAltered(bool a_set) override;                                    // 24

    std::uint32_t  data;        // 28
    std::uint32_t  unknown2C;       // 2C
    TESObjectCELL* parentCell;  // 30
    std::uint64_t  unk38[2];    // 38
};
static_assert(sizeof(TESObjectLAND) == 0x48, "layout");


}
