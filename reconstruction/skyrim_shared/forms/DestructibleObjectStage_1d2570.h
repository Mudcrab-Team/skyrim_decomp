// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSDestructibleObjectForm.cpp:45
// DestructibleObjectStage, DestructibleObjectStage::CheckReplacementModel: SIBLING(fo4-private@1b765c70, author-permission)
// BSFixedString::QLength: GUESS(low); name from the sibling call site
// DestructibleObjectStage::replacementModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG types it TESModelTextureSwap*
// TESModel, TESModel::model, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSFixedString
{
public:
    std::uint32_t QLength() const;

    const char* data;  // 00
};

class TESModel
{
public:
    virtual ~TESModel();  // 00

    BSFixedString model;  // 08
    std::uint8_t unknown10[0x18];  // 10
};
static_assert(sizeof(TESModel) == 0x28, "TESModel size");

class DestructibleObjectStage
{
public:
    void CheckReplacementModel();

    std::uint8_t unknown00[0x20];  // 00
    TESModel* replacementModel;  // 20
};
static_assert(sizeof(DestructibleObjectStage) == 0x28, "DestructibleObjectStage size");
