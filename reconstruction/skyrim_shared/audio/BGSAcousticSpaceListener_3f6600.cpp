// Source exposure: mixed (assigned pinned-image pack; community callee name).
// Code origin: original reconstruction by gpt-6.1-sol; no adapted bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESObjectCELL::GetbhkWorld: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSAcousticSpaceListener::GetAcousticWorldData: GUESS(low); behavior-derived name, not identity evidence.
// BGSAcousticSpaceListener, BGSAcousticSpaceListener::GetAcousticWorldData, CellOwner, PhysicsWorld, acousticData, unknown00, owner, cell: GUESS(low); local names; layout inferred from assigned accesses.
// 0x3f6600 BGSAcousticSpaceListener::GetAcousticWorldData
#include "BGSAcousticSpaceListener_3f6600.h"

void* BGSAcousticSpaceListener::GetAcousticWorldData() const
{
    if (owner && owner->cell) {
        TESObjectCELL::PhysicsWorld* world = owner->cell->GetbhkWorld();
        if (world) {
            return world->acousticData;
        }
    }
    return nullptr;
}
