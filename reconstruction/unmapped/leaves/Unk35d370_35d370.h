// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: Unk35d370::Function35d370.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00500000_o2.cpp:5346
// Unk35d370, Unk35d370::Function35d370: GUESS(low); placeholder owner for a free function of the image
// ResolveLookupParameter, ApplyLookupValue: GUESS(low); local names for two callees whose identity in this image is unknown; their shape follows the sibling body
// PlayerCharacter, OBJ_REFR, TESBoundObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::singleton: GUESS(low); a name for the global pointer the image reads, NG reaches it through GetSingleton
// PlayerCharacter::data, OBJ_REFR::objectReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// baseMembers: GUESS(low); the members of the base classes up to the reference data
#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject;

struct OBJ_REFR
{
    TESBoundObject* objectReference;  // 00
};

class PlayerCharacter
{
public:
    static PlayerCharacter* singleton;

    std::uint8_t baseMembers[0x40];  // 00
    OBJ_REFR data;                // 40
};

bool ResolveLookupParameter(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, TESBoundObject** a8);
void ApplyLookupValue(void* a1, TESBoundObject* a2, int a3, double* a4);

class Unk35d370
{
public:
    static bool Function35d370(void* a1, void* a2, void* object, void* a4, void* a5, void* a6, double* out, void* a8);  // compared: 0x35d370
};
