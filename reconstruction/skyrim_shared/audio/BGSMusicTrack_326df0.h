// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:45
// BGSMusicTrack, BGSMusicTrack::~BGSMusicTrack, BGSMusicTrack::LoadConditions, TESCondition, TESCondition::LoadCompact, TESFile: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
// BSIMusicTrack, BSIMusicTrack::~BSIMusicTrack: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base only stores its vftable
// MemMgrGuard_369ac98, MemMgrInst_369a810, MemMgrEnsure_cde810, MemMgrAlloc_cde250: GUESS(low); the memory manager singleton guard, instance, init and allocation callees, named by address
// BGSMusicTrack::unk18, TESCondition::head: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pConditions, unk08: GUESS(low); pConditions is the member name the sibling body uses
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
}

void MemMgrEnsure_cde810(void* self, std::uint32_t* state);
void* MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);

class TESFile;

class TESCondition
{
public:
    TESCondition();
    ~TESCondition();
    void LoadCompact(TESFile* apFile);

    // The allocation goes through the memory manager singleton, initialised on first use.
    static void* operator new(std::size_t size) throw()
    {
        if (MemMgrGuard_369ac98 != 2u)
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        return MemMgrAlloc_cde250(MemMgrInst_369a810, size, 0u, false);
    }

    void* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

class BSIMusicTrack
{
public:
    virtual ~BSIMusicTrack() {}

    std::uint64_t unk08;  // 08
};

class BGSMusicTrack : public BSIMusicTrack
{
public:
    BGSMusicTrack() { pConditions = nullptr; }
    ~BGSMusicTrack() override;

    void LoadConditions(TESFile* apFile);

    TESCondition* pConditions;  // 10
    std::uint64_t unk18;        // 18
};
static_assert(sizeof(BGSMusicTrack) == 0x20, "BGSMusicTrack size");
