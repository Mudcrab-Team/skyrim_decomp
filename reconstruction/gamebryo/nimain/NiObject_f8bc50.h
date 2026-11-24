// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, BSAnimNote, BSLookIKNote: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal stand-ins, only what this unit touches
// _refCount, _pad0C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiRefObject members, declared here instead of a base class
// fTime, m_fDistanceScale, eState: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// m_eType: GUESS(low)
// a_time: GUESS(low); the type value 2 is read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    volatile std::uint32_t _refCount;  // 08
    std::uint32_t          _pad0C;     // 0C
};
static_assert(sizeof(NiObject) == 0x10, "NiObject layout differs from the community header");

class BSAnimNote : public NiObject
{
public:
    explicit BSAnimNote(float a_time) :
        fTime(a_time)
    {
    }
    ~BSAnimNote() override;

    std::uint32_t m_eType;  // 10
    float         fTime;    // 14
};

class BSLookIKNote : public BSAnimNote
{
public:
    explicit BSLookIKNote(float a_time);  // compared: 0xf8bc50
    ~BSLookIKNote() override;

    float        m_fDistanceScale;  // 18
    std::int32_t eState;            // 1C
};
static_assert(sizeof(BSLookIKNote) == 0x20, "BSLookIKNote size differs from the observed layout");
