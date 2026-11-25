// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicType, BGSMusicType::~BGSMusicType, BGSMusicType::GetFormEditorID, BGSMusicType::SetFormEditorID, BGSMusicType::DoPause, BGSMusicType::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIMusicType, BSIMusicType::DoUpdate, ::DoPlay, ::DoPause, ::DoFinish, ::DoApplyDuckingAttenuation, ::DoClearDucking, ::DoPrepare, ::flags, ::priority, ::ducksOtherMusicBy, ::fadeTime, ::currentTrackIndex, ::trackHistory, ::tracks, ::typeStatus: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout as in NG, size 0x50
// BSIMusicType::~BSIMusicType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); last slot, 07
// BSIMusicTrack, BSIMusicTrack::DoUpdate, ::DoPlay, ::DoPause: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slot order 00 to 03 is claimed
// BSTArray, BSTArray::_size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; data, capacity and size read from the listing
// BSTArray::_data, ::_capacity, ::Clear: GUESS(low); the allocator pointer and capacity (with the padding after it); Clear releases the storage and zeroes the count
// ReleaseMusicArray: GUESS(low); the allocator release the target calls
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a single string pointer
// BGSMusicType::BGSMusicType: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); name only
#pragma once

#include <cstdint>

#include "../forms/TESForm.h"

class BSFixedString {
public:
    ~BSFixedString();
    BSFixedString& operator=(const char* a_str);

    const char* _data;  // 00
};

class BSIMusicTrack {
public:
    virtual ~BSIMusicTrack();     // 00
    virtual void DoUpdate();      // 01
    virtual void DoPlay();        // 02
    virtual void DoPause();       // 03
};

void ReleaseMusicArray(void*);

template <class T>
struct BSTArray {
    void Clear() { if (_data) { ReleaseMusicArray(this); _size = 0; } }

    T*            _data;      // 00
    std::uint64_t _capacity;  // 08
    std::uint32_t _size;      // 10
};

class BSIMusicType {
public:
    virtual void DoUpdate();                                      // 00
    virtual void DoPlay();                                        // 01
    virtual void DoPause();                                       // 02
    virtual void DoFinish(bool a_arg1);                           // 03
    virtual void DoApplyDuckingAttenuation(std::uint16_t a_ducking);  // 04
    virtual void DoClearDucking();                                // 05
    virtual void DoPrepare();                                     // 06
    virtual ~BSIMusicType();                                      // 07

    std::uint32_t            flags;              // 08
    std::uint8_t             priority;           // 0C
    std::uint16_t            ducksOtherMusicBy;  // 0E
    float                    fadeTime;           // 10
    std::uint32_t            currentTrackIndex;  // 14
    BSTArray<std::uint32_t>  trackHistory;       // 18
    BSTArray<BSIMusicTrack*> tracks;             // 30
    std::uint32_t            typeStatus;         // 48
};
static_assert(sizeof(BSIMusicType) == 0x50, "layout");

class BGSMusicType :
    public TESForm,      // 00
    public BSIMusicType  // 20
{
public:
    BGSMusicType();
    ~BGSMusicType() override;  // 00

    const char* GetFormEditorID() const override;             // 32
    bool        SetFormEditorID(const char* a_str) override;  // 33

    void DoPause() override;  // BSIMusicType 02

    BSFixedString formEditorID;  // 70
};
static_assert(sizeof(BGSMusicType) == 0x78, "layout");
