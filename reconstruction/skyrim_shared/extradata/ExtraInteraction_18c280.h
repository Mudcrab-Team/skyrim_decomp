// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraInteraction, ExtraInteraction::interaction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraInteraction::ExtraInteraction: CRASHLOGGER_PDB(59818@2026.10.24); a constructor taking the shared interaction pointer
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order 00 to 02
// RefrInteraction: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward-declared there, only the intrusive count at +08 is used
// RefrInteraction::unk00, ::refCount, RefrInteractionPtr, RefrInteractionPtr::ptr: GUESS(low); the pointer wrapper stands in for NG's BSTSmartPointer<RefrInteraction>
// ExtraInteraction::GetType, ::IsNotEqual, ::~ExtraInteraction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared so the class has the vtable the constructor stores
#pragma once

#include <cstdint>
#include <intrin.h>

// abstract base (GetType is pure in the community header): its own vtable is never installed
class __declspec(novtable) BSExtraData
{
public:
    BSExtraData() : next(nullptr) {}
    virtual ~BSExtraData() {}                              // 00
    virtual std::uint32_t GetType() const = 0;              // 01
    virtual bool IsNotEqual(const BSExtraData* a_rhs) const;  // 02

    BSExtraData* next;  // 08
};

struct RefrInteraction
{
    void* unk00;           // 00
    volatile long refCount;  // 08
};

class RefrInteractionPtr
{
public:
    RefrInteractionPtr(const RefrInteractionPtr& a_rhs) : ptr(a_rhs.ptr)
    {
        if (a_rhs.ptr) {
            // the interaction is shared with other holders, so the count changes atomically
            _InterlockedIncrement(&a_rhs.ptr->refCount);
        }
    }

    RefrInteraction* ptr;
};

class ExtraInteraction : public BSExtraData
{
public:
    explicit ExtraInteraction(const RefrInteractionPtr& a_interaction);

    ~ExtraInteraction() override;
    std::uint32_t GetType() const override;
    bool IsNotEqual(const BSExtraData* a_rhs) const override;

    RefrInteractionPtr interaction;  // 10
};
static_assert(sizeof(ExtraInteraction) == 0x18, "ExtraInteraction size");
