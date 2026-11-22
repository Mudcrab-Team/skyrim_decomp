// Source exposure: mixed (pinned target image, community headers).
// Code origin: adapted pinned community declarations and target-informed typed prefix stand-ins; no sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/extradata/ExtraDataList.h"
namespace ResearchLayouts {
class TESObjectCELLExtraPrefixLayout : public TESForm, public TESFullName {
public:
    TESGlobal* GetGlobal() const; // Inferred unless supported by community declarations
    unsigned int GetDetachTime() const; // Inferred unless supported by community declarations
    BGSAcousticSpace* GetAcousticSpace() const; // Inferred unless supported by community declarations
    BSSpinLock grassCreateLock;
    BSSpinLock grassTaskLock;
    std::uint16_t cellFlags;
    std::uint16_t cellGameFlags;
    std::uint8_t cellState;
    bool autoWaterLoaded;
    bool cellDetached;
    std::uint8_t pad047;
    ExtraDataList extraList;
};
static_assert(offsetof(TESObjectCELLExtraPrefixLayout, extraList) == 0x48, "target member address");
}
