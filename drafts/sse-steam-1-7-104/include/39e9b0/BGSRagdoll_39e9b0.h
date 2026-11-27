// Exposure detail: (community declarations and binary analysis).
// Source exposure: mixed
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSRagdoll, BGSRagdoll::~BGSRagdoll, TESModel, BGSRagdoll::unk098, BGSRagdoll::unk048, BGSRagdoll::unk0B0, BGSRagdoll::unk100, BGSRagdoll::unk138, BGSRagdoll::unk178: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ClearRagdollData, RagdollArray, RagdollCount, RagdollStorage, Release, Reset, ClearAllocator: GUESS(low)
// unk08, RagdollPartData, RagdollTail: GUESS(low)
// Adapted bodies: BGSRagdoll::~BGSRagdoll follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsragdoll.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsragdoll.cpp:962
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsragdoll.cpp:546

#pragma once

#include <cstdint>
#include "../../../../reconstruction/declarations/TESForm.h"

class TESModel : public BaseFormComponent
{
public:
    ~TESModel() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    std::uint8_t unk08[0x20];
};

template <unsigned Size>
struct RagdollPartData
{
    ~RagdollPartData();
    std::uint8_t storage[Size];
};

struct RagdollTail
{
    ~RagdollTail();
    std::uint8_t storage[0x40];
};

struct RagdollStorage
{
    ~RagdollStorage();
    void Release();

    void* data;
    std::uint32_t capacity;
};

struct RagdollCount
{
    void ClearAllocator();
    void Reset(bool initialized)
    {
        if (initialized)
            value = 0;
        else
            ClearAllocator();
    }

    std::uint32_t value;
};

struct RagdollArray : RagdollStorage, RagdollCount
{
    ~RagdollArray()
    {
        const bool initialized = data != nullptr;
        if (initialized)
            Release();
        Reset(initialized);
    }

};

class BGSRagdoll : public TESForm, public TESModel
{
public:
    BGSRagdoll();
    ~BGSRagdoll() override;
    void ClearRagdollData();

    std::uint8_t unk048[0x50];
    RagdollArray unk098;
    RagdollPartData<0x50> unk0B0;
    RagdollPartData<0x38> unk100;
    RagdollPartData<0x40> unk138;
    RagdollTail unk178;
};
static_assert(sizeof(BGSRagdoll) == 0x1B8, "BGSRagdoll size");
