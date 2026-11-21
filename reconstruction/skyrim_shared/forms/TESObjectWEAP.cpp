// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x28e810 TESObjectWEAP::GetPlayable
// 0x28e7f0 TESObjectWEAP::GetObjectTypeName
// 0x28e7b0 TESObjectWEAP::GetDescriptionOwnerFile
// 0x28e500 TESObjectWEAP::~TESObjectWEAP
// 0x28c020 TESObjectWEAP::Function28c020
// 0x28c260 TESObjectWEAP::Function28c260
#include "TESObjectWEAP.h"

// kObjectTypeNames: GUESS(low); the table of type name strings indexed by unk19D
extern const char* kObjectTypeNames[];

// ResolveOwnerFile: GUESS(low); the callee takes the form and a 32-bit index, and returns the file
TESFile* ResolveOwnerFile(const TESForm* a_form, std::uint32_t a_index);

// ImpactDataSetFunction31e710: GUESS(low); the callee at 0x31e710 takes the impact data set and returns a pointer
void* ImpactDataSetFunction31e710(BGSImpactDataSet* a_set);

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESObjectWEAP::TESObjectWEAP()
{
}

bool TESObjectWEAP::GetPlayable() const
{
    return ~(unk19E >> 7) & 1;
}

const char* TESObjectWEAP::GetObjectTypeName() const
{
    return kObjectTypeNames[static_cast<std::uint32_t>(unk19D)];
}

TESFile* TESObjectWEAP::GetDescriptionOwnerFile() const
{
    return ResolveOwnerFile(unknown208 != nullptr ? unknown208 : this, 0xFFFFFFFFu);
}

void* TESObjectWEAP::Function28c020()
{
    if (impactDataSet) {
        return ImpactDataSetFunction31e710(impactDataSet);
    }
    return nullptr;
}

std::uint32_t TESObjectWEAP::Function28c260()
{
    std::int32_t index = unk19D;
    return (index >= -1 && index < 7) + 1;
}
