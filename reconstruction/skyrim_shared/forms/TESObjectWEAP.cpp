// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: written for this project from the listing; declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x28e810 TESObjectWEAP::GetPlayable
// 0x28e7f0 TESObjectWEAP::GetObjectTypeName
// 0x28e7b0 TESObjectWEAP::GetDescriptionOwnerFile
// 0x28e500 TESObjectWEAP::~TESObjectWEAP
// 0x28e7d0 TESObjectWEAP::GetNumProjectiles
// g_defaultNumProjectiles: GUESS(low); the byte returned when the weapon has no ranged data
#include "TESObjectWEAP.h"

extern std::uint8_t g_defaultNumProjectiles;

std::uint8_t TESObjectWEAP::GetNumProjectiles() const
{
    if (rangedData) {
        return rangedData->numProjectiles;
    }
    return g_defaultNumProjectiles;
}

// kObjectTypeNames: GUESS(low); the table of type name strings indexed by unk19D
extern const char* kObjectTypeNames[];

// ResolveOwnerFile: GUESS(low); the callee takes the form and a 32-bit index, and returns the file
TESFile* ResolveOwnerFile(const TESForm* a_form, std::uint32_t a_index);

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
