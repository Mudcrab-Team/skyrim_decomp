// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPatrolRefData: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PatrolRefData, patrolData: CRASHLOGGER_PDB(59818@2026.10.24)
// PatrolRefData::IsNotEqual: GUESS(low)
#pragma once
#include <cstdint>
#include "BSExtraData.h"

class PatrolRefData
{
public:
    bool IsNotEqual(const PatrolRefData* a_rhs) const;
};

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraPatrolRefData : public BSExtraData
{
public:
    bool IsNotEqual(const BSExtraData* a_rhs) const override;
    virtual std::uint32_t GetType() const;

    PatrolRefData* patrolData;  // 10
};
