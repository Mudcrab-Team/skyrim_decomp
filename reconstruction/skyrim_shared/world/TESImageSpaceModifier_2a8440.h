// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImageSpaceModifier::MakeDefaultGetHit: CRASHLOGGER_PDB(59818@2026.10.24); name only
// TESImageSpaceModifier, TESImageSpaceModifier::data, ImageSpaceModifierData, ImageSpaceModifierData::animatable: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// TESForm, TESForm::InitializeDataComponent, TESForm::ClearDataComponent, TESForm::CopyComponent, TESForm::InitializeData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the vtable slots up to InitializeData and the members up to 20
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
{
public:
    virtual ~TESForm();
    virtual void InitializeDataComponent();            // 01
    virtual void ClearDataComponent();                 // 02
    virtual void CopyComponent(void* a_source);        // 03
    virtual void InitializeData();                     // 04

    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

struct ImageSpaceModifierData
{
    bool animatable;                 // 00
    std::uint8_t unk01[0xF4 - 0x1];  // 01
};
static_assert(sizeof(ImageSpaceModifierData) == 0xF4, "data size");

class TESImageSpaceModifier : public TESForm
{
public:
    void MakeDefaultGetHit();  // compared: 0x2a8440
    void InitializeData() override;

    ImageSpaceModifierData data;  // 20
};
static_assert(offsetof(TESImageSpaceModifier, data) == 0x20, "data offset");
