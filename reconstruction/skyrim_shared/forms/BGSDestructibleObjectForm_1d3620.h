// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSDestructibleObjectForm.cpp:144
// BGSDestructibleObjectForm, BGSDestructibleObjectForm::GetModelSwap, BGSDestructibleObjectForm::GetDestructionForm: SIBLING(fo4-private@1b765c70, author-permission)
// BGSDestructibleObjectForm::data, DestructibleObjectData, DestructibleObjectData::numStages, DestructibleObjectData::stages, DestructibleObjectStage, DestructibleObjectStage::replacementModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, TESModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00, unknown10, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm;
class TESModel;

class DestructibleObjectStage
{
public:
    std::uint8_t unknown00[0x20];  // 00
    TESModel* replacementModel;    // 20
    std::uint8_t unknown28[0x8];   // 28
};

class DestructibleObjectData
{
public:
    std::uint8_t unknown00[0x4];        // 00
    std::uint8_t numStages;            // 04
    std::uint8_t unknown05[0x3];        // 05
    DestructibleObjectStage** stages;   // 08
};

class BGSDestructibleObjectForm
{
public:
    static TESModel* GetModelSwap(TESForm* a_form, int a_modelSwapIndex);
    static BGSDestructibleObjectForm* GetDestructionForm(TESForm* a_form);

    std::uint8_t unknown00[0x8];  // 00
    DestructibleObjectData* data;  // 08
};
