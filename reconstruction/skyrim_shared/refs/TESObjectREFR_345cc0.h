// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, TESObjectREFR::Function345cc0, RefListNode, gRefListLock, gRefListBb8, EnterRefListLock, LeaveRefListLock: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR
{
public:
    static bool Function345cc0(TESObjectREFR* refr);
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
extern RefListNode gRefListBb8;

extern "C" void __declspec(dllimport) EnterRefListLock(RefListLock* lock);
extern "C" void __declspec(dllimport) LeaveRefListLock(RefListLock* lock);
