// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSConstructibleObject, TESBoundObject, PlayerCharacter, RemoveItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RemoveRequiredItem, singleton, vtable, slots: GUESS(low); inferred full-width callback result and partial virtual layout
#pragma once

#include <cstddef>

class TESBoundObject;
class PlayerCharacter
{
public:
    struct VirtualTable
    {
        void* slots[0x56];
        void (*RemoveItem)(PlayerCharacter*, unsigned*, TESBoundObject*, int, unsigned, void*, void*, void*, void*);
    };
    VirtualTable* vtable;
    static PlayerCharacter* singleton;
};

class BGSConstructibleObject
{
public:
    static unsigned int RemoveRequiredItem(TESBoundObject*, int);
};
static_assert(offsetof(PlayerCharacter::VirtualTable, RemoveItem) == 0x2b0, "inventory removal virtual slot");
