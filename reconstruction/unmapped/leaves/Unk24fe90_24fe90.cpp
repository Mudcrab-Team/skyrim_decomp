// CI hash: 0x24fe90 ??0Unk24fe90@@QEAA@AEBV0@@Z
// Source exposure: mixed.
// Code origin: original observed copy sequence after studying the labelled sibling constructor.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/region system/tesregiondata.cpp (copy constructor; CC0-1.0).
// Unk24fe90: STANDIN GUESS(low)
// Unk24fe90::Unk24fe90: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// Unk24fe90::~Unk24fe90, Unk24fe90::LoadDataHeader, Unk24fe90::LoadData, Unk24fe90::GetType, Unk24fe90::ConstructSelf, Unk24fe90::Unk_05, Unk24fe90::CopyFrom, Unk24fe90::IsLoaded, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk24fe90::unk08, Unk24fe90::unk09, Unk24fe90::unk0a: OBSERVED
// 0x24fe90 Unk24fe90::Unk24fe90
#include "Unk24fe90_24fe90.h"

// Copy the three stored region-data attributes.
Unk24fe90::Unk24fe90(const Unk24fe90& other)
{
    unk08 = other.unk08;
    unk0a = other.unk0a;
    unk09 = other.unk09;
}
