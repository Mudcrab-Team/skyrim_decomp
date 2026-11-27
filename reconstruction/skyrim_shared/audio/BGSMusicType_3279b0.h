// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicType, BGSMusicType::DoUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the body works on the BSIMusicType subobject (offsets are relative to it), so this class is a stand-in for that view
// BGSMusicType::flags, ::currentTrackIndex, ::tracks, ::typeStatus: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members of BSIMusicType
// MST, MUSIC_STATUS: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the enumerators the body tests
// MSTFlags: GUESS(low); stands in for the community enumeration wrapper over a 32-bit word, with the two accessors any and set
// BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); data pointer, capacity and size only
// BSIMusicTrack, BSIMusicTrack::DoUpdate, BSIMusicTrack::GetMusicStatus: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots up to GetMusicStatus
// BSIMusicTrack::unk02, ::unk03, ::unk04, ::unk05, ::unk06, ::unk07: GUESS(low); slot placeholders
// BGSMusicType::unk00, ::unk0C, ::unk18: GUESS(low); unused regions of the subobject
// BGSMusicType::DoUpdate: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

#include <cstdint>
#include <cstddef>

class BSIMusicTrack
{
public:
    virtual ~BSIMusicTrack();  // 00
    virtual void DoUpdate();  // 01
    virtual void unk02();  // 02
    virtual void unk03();  // 03
    virtual void unk04();  // 04
    virtual void unk05();  // 05
    virtual void unk06();  // 06
    virtual void unk07();  // 07
    virtual std::uint32_t GetMusicStatus();  // 08
};

class MSTFlags
{
public:
    bool any(std::uint32_t a_flags) const { return (_impl & a_flags) != 0; }
    void set(std::uint32_t a_flags) { _impl |= a_flags; }

    std::uint32_t _impl;  // 00
};

template <class T>
class BSTArray
{
public:
    std::uint32_t size() const { return _size; }
    T& operator[](std::uint32_t a_pos) { return _data[a_pos]; }

    T* _data;  // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint32_t _size;  // 10
};

class BGSMusicType
{
public:
    enum MST : std::uint32_t
    {
        kPlaysOnce = 1 << 0,
        kRemovalQueued = 1 << 4
    };

    enum MUSIC_STATUS : std::uint32_t
    {
        kInactive = 0,
        kFinishing = 3,
        kFinished = 4
    };

    void DoUpdate();  // compared: 0x3279b0

    std::uint8_t unk00[0x8];  // 00
    MSTFlags flags;  // 08
    std::uint8_t unk0C[0x8];  // 0C
    std::uint32_t currentTrackIndex;  // 14
    std::uint8_t unk18[0x18];  // 18
    BSTArray<BSIMusicTrack*> tracks;  // 30
    std::uint32_t typeStatus;  // 48
};
static_assert(sizeof(BGSMusicType) == 0x50, "BGSMusicType subobject view size");
