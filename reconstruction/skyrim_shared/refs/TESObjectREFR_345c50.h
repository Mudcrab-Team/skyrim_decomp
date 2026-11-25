// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, TESObjectREFR::Function345c50, RefListNode, gRefListLock, gRefListBc8, EnterRefListLock, LeaveRefListLock: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR
{
public:
    static bool Function345c50(TESObjectREFR* refr);
};

struct RefListNode
{
    TESObjectREFR* ref;
    RefListNode* next;
};

struct RefListLock
{
    std::uint8_t storage[0x28];
};

extern RefListLock gRefListLock;
extern RefListNode gRefListBc8;

extern "C" void __declspec(dllimport) EnterRefListLock(RefListLock* lock);
extern "C" void __declspec(dllimport) LeaveRefListLock(RefListLock* lock);
