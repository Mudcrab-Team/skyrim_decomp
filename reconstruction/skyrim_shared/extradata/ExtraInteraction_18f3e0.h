// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// ExtraInteraction, ~ExtraInteraction, interaction, BSExtraData, ~BSExtraData, GetType, IsNotEqual, next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RefrInteraction: CRASHLOGGER_PDB(59818@2026.10.24)
// refCount: GUESS(low); observed intrusive count at offset 0x08.
// BSTSmartPointerRefrInteraction, object, ptr: GUESS(low); reduced intrusive pointer wrapper.
// ~RefrInteraction: GUESS(low); observed virtual lifetime boundary.
// 0x18f3e0 ExtraInteraction::~ExtraInteraction
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class BSExtraData {
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData*) const;
    BSExtraData* next;
};
#include <intrin.h>
class RefrInteraction {
public:
    virtual ~RefrInteraction();
    volatile long refCount; // volatile: atomic access to the observed shared intrusive count.
};
class BSTSmartPointerRefrInteraction {
public:
    ~BSTSmartPointerRefrInteraction()
    {
        RefrInteraction* object = ptr;
        // Atomic release of the intrusive count preserves concurrent ownership.
        if (object && _InterlockedExchangeAdd(&object->refCount, -1) == 1) {
            delete object;
        }
    }
    RefrInteraction* ptr;
};
class ExtraInteraction : public BSExtraData {
public:
    ExtraInteraction();
    ~ExtraInteraction() override = default;
    BSTSmartPointerRefrInteraction interaction;
};
static_assert(sizeof(ExtraInteraction) == 0x18, "ExtraInteraction size");
