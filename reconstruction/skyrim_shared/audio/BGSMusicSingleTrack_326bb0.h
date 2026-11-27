// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicSingleTrack: EXE_RTTI
// BGSMusicSingleTrack::~BGSMusicSingleTrack: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSMusicTrack, BSTArrayBase, BSTArrayHeapAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMusicTrack::unk08, BSTArrayHeapAllocator::data, BSTArrayHeapAllocator::capacity, BSTArrayHeapAllocator::Deallocate, BSTArrayBase::size, BSTArray, LoopData, LoopData::unk00, BGSMusicSingleTrack::unk20, BGSMusicSingleTrack::cuePoints, BGSMusicSingleTrack::unk50, BGSMusicSingleTrack::loopInfo, BGSMusicSingleTrack::unk68: GUESS(low); layout and destructor calls observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class BGSMusicTrack
{
public:
    virtual ~BGSMusicTrack();  // 00

    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(BGSMusicTrack) == 0x20, "BGSMusicTrack size");

struct BSTArrayHeapAllocator
{
    ~BSTArrayHeapAllocator();
    void Deallocate();

    void*         data;      // 00
    std::uint32_t capacity;  // 08
};
static_assert(sizeof(BSTArrayHeapAllocator) == 0x10, "BSTArrayHeapAllocator size");

struct BSTArrayBase
{
    ~BSTArrayBase();

    std::uint32_t size;  // 00
};

struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase
{
    ~BSTArray()
    {
        if (data) {
            Deallocate();
            size = 0;
        }
    }
};
static_assert(sizeof(BSTArray) == 0x18, "BSTArray size");

struct LoopData
{
    std::uint8_t unk00[0xC];  // 00
};
static_assert(sizeof(LoopData) == 0xC, "LoopData size");

class BGSMusicSingleTrack : public BGSMusicTrack
{
public:
    BGSMusicSingleTrack();
    ~BGSMusicSingleTrack() override;

    std::uint8_t unk20[0x18];  // 20
    BSTArray     cuePoints;    // 38
    std::uint8_t unk50[0x10];  // 50
    LoopData*    loopInfo;     // 60
    std::uint8_t unk68[0x18];  // 68
};
static_assert(offsetof(BGSMusicSingleTrack, cuePoints) == 0x38, "cuePoints offset");
static_assert(offsetof(BGSMusicSingleTrack, loopInfo) == 0x60, "loopInfo offset");
static_assert(sizeof(BGSMusicSingleTrack) == 0x80, "BGSMusicSingleTrack size");
