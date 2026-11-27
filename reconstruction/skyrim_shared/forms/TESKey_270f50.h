// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESKey, TESKey::~TESKey, TESBoundObject, TESObjectMISC, TESObjectMISC::~TESObjectMISC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName, TESModelTextureSwap, TESIcon, TESValueForm, TESWeightForm, BGSDestructibleObjectForm, BGSMessageIcon, BGSPickupPutdownSounds, BGSKeywordForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk20: GUESS(low)
// Adapted bodies: TESKey::~TESKey follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teskey.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teskey.cpp:13
#pragma once

#include <cstdint>
#include "declarations/TESForm.h"

class TESBoundObject : public TESForm
{
public:
    std::uint8_t unk20[0x10];
};

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x8];
};

class TESModelTextureSwap : public BaseFormComponent
{
public:
    ~TESModelTextureSwap() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x30];
};

class TESIcon : public BaseFormComponent
{
public:
    ~TESIcon() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x8];
};

class TESValueForm : public BaseFormComponent
{
public:
    ~TESValueForm() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x8];
};

class TESWeightForm : public BaseFormComponent
{
public:
    ~TESWeightForm() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x8];
};

class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
    ~BGSDestructibleObjectForm() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x8];
};

class BGSMessageIcon : public BaseFormComponent
{
public:
    ~BGSMessageIcon() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x10];
};

class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    ~BGSPickupPutdownSounds() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x10];
};

class BGSKeywordForm : public BaseFormComponent
{
public:
    ~BGSKeywordForm() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x10];
};

class TESObjectMISC :
    public TESBoundObject,
    public TESFullName,
    public TESModelTextureSwap,
    public TESIcon,
    public TESValueForm,
    public TESWeightForm,
    public BGSDestructibleObjectForm,
    public BGSMessageIcon,
    public BGSPickupPutdownSounds,
    public BGSKeywordForm
{
public:
    ~TESObjectMISC() override;
};

class TESKey : public TESObjectMISC
{
public:
    TESKey();
    ~TESKey() override;
};
static_assert(sizeof(TESKey) == 0x100, "TESKey size");
