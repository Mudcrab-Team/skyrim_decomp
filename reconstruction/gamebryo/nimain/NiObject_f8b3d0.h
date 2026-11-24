// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, BSAnimNote, BSGrabIKNote: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal stand-ins, only what this unit touches
// _refCount, _pad0C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiRefObject members, declared here instead of a base class
// fTime: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// m_eType, m_eArm, m_fGain, m_eAnimationState: GUESS(low)
// a_type: GUESS(low); the type value 1 is read from the listing
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
    explicit BSAnimNote(std::uint32_t a_type) :
        m_eType(a_type),
        fTime(0.0f)
    {
    }
    ~BSAnimNote() override;

    std::uint32_t m_eType;  // 10
    float         fTime;    // 14
};

class BSGrabIKNote : public BSAnimNote
{
public:
    BSGrabIKNote();  // compared: 0xf8b3d0
    ~BSGrabIKNote() override;

    std::uint32_t m_eArm;             // 18
    float         m_fGain;            // 1C
    std::uint32_t m_eAnimationState;  // 20
};
static_assert(sizeof(BSGrabIKNote) == 0x28, "BSGrabIKNote size differs from the observed layout");
