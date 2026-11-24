// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraReflectorRefs, ExtraReflectorRefs::refs, ExtraReflectorRefs::IsNotEqual, ExtraReflectorRefs::GetType, ExtraReflectorRefs::~ExtraReflectorRefs: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraReflectorRefs::IsNotEqual: CRASHLOGGER_PDB(59818@2026.10.24); the PDB name is IsEqual, the body returns true when the lists differ and sits in slot 02, so the NG name is kept
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order 00 to 02
// RefHandleArray, RefHandleArray::data, ::capacity, ::size: GUESS(low) STANDIN; a BSTArray of 32-bit object handles with the layout read from the listing
#pragma once

#include <cstdint>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}                                 // 00
    virtual std::uint32_t GetType() const;                    // 01
    virtual bool IsNotEqual(const BSExtraData* a_rhs) const;  // 02

    BSExtraData* next;  // 08
};

struct RefHandleArray
{
    std::uint32_t* data;      // 00
    std::uint32_t capacity;   // 08
    std::uint32_t pad0C;      // 0C
    std::uint32_t size;       // 10
    std::uint32_t pad14;      // 14
};

class ExtraReflectorRefs : public BSExtraData
{
public:
    ~ExtraReflectorRefs() override;
    std::uint32_t GetType() const override;
    bool IsNotEqual(const BSExtraData* a_rhs) const override;

    RefHandleArray refs;  // 10
};
static_assert(sizeof(ExtraReflectorRefs) == 0x28, "ExtraReflectorRefs size");
