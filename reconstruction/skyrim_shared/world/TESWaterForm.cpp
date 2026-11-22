// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// kEnableFlowmapBit, kBlendNormalsBit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kUnknownWaterFlagBit: OBSERVED
// 0x306f80 TESWaterForm::GetDangerous
// 0x3078e0 TESWaterForm::~TESWaterForm
// 0x306fc0 TESWaterForm::Function306fc0
// 0x307010 TESWaterForm::Function307010
// 0x307060 TESWaterForm::Function307060
#include "TESWaterForm.h"

namespace {
constexpr unsigned kUnknownWaterFlagBit = 2;
constexpr unsigned kEnableFlowmapBit = 3;
constexpr unsigned kBlendNormalsBit = 4;
}

// Not compared: defined so that this unit emits the vftable and with it the deleting destructor.
TESWaterForm::TESWaterForm()
{
}

bool TESWaterForm::GetDangerous() const
{
    return flags & 1;
}
// Return the water's unnamed flag at bit 2.
bool TESWaterForm::Function306fc0() const
{
    return (flags >> kUnknownWaterFlagBit) & 1;
}

// Report whether the water uses a flow map.
bool TESWaterForm::Function307010() const
{
    return (flags >> kEnableFlowmapBit) & 1;
}

// Report whether the water blends normals.
bool TESWaterForm::Function307060() const
{
    return (flags >> kBlendNormalsBit) & 1;
}
