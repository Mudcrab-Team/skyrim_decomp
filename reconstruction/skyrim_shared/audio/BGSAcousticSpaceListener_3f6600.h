// Source exposure: mixed (assigned pinned-image pack; community callee name).
// Code origin: original reconstruction by gpt-6.1-sol; no adapted bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESObjectCELL::GetbhkWorld: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSAcousticSpaceListener::GetAcousticWorldData: GUESS(low); behavior-derived name, not identity evidence.
// BGSAcousticSpaceListener, BGSAcousticSpaceListener::GetAcousticWorldData, CellOwner, PhysicsWorld, acousticData, unknown00, owner, cell: GUESS(low); local names; layout inferred from assigned accesses.
// 0x3f6600 BGSAcousticSpaceListener::GetAcousticWorldData
#pragma once
#include <cstdint>

class TESObjectCELL
{
public:
    struct PhysicsWorld
    {
        std::uint8_t unknown00[0xC5C8];
        void* acousticData;
    };
    PhysicsWorld* GetbhkWorld();
};
class BGSAcousticSpaceListener
{
public:
    struct CellOwner
    {
        std::uint8_t unknown00[0x60];
        TESObjectCELL* cell;
    };
    void* GetAcousticWorldData() const;
    CellOwner* owner;
};
