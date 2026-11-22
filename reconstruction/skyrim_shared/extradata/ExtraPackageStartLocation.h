// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPackageStartLocation: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WORLD_LOCATION, worldLoc, locationForm, locPt, zRot: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>
#include "BSExtraData.h"

class TESForm;

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraPackageStartLocation : public BSExtraData
{
public:
    struct WORLD_LOCATION
    {
        TESForm* locationForm;  // 00
        float locPt[3];         // 08
        float zRot;             // 14
    };

    bool IsNotEqual(const BSExtraData* a_rhs) const override;
    virtual std::uint32_t GetType() const;

    WORLD_LOCATION worldLoc;  // 10
};
