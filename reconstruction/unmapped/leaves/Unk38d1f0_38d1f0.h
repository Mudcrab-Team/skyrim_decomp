// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: Unk38d1f0::ApplyFunction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/bgsentrypointfunction.cpp:33
// Unk38d1f0: GUESS(low); placeholder owner, the real class of the static function is not known
// BGSEntryPointFunction::ENTRY_POINT_FUNCTION, BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE, BGSEntryPointFunction::EntryPointFunctionInfo, BGSEntryPointFunction::ApplyFunction: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// BGSEntryPointFunction::ms_kEntryPointFunctionTable, EntryPointFunctionInfo::pFunction, EntryPointFunctionInfo::pFunctionName, EntryPointFunctionInfo::m_eFunctionType: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); only the handler at offset 0 and the entry size are observed
// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only named in a pointer parameter
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR;

class Unk38d1f0
{
public:
    enum ENTRY_POINT_FUNCTION
    {
        NONE = 0,
        SET_VALUE = 1,
        ADD_VALUE = 2,
        MULTIPLY_VALUE = 3,
        ADD_RANGE_TO_VALUE = 4,
        ADD_ACTOR_VALUE_MULT = 5,
        ABSOLUTE_VALUE = 6,
        NEGATIVE_ABSOLUTE_VALUE = 7,
        ADD_LEVELED_LIST_TO_TARGET = 8,
        ADD_ACTIVATE_CHOICE = 9,
        ENTRY_POINT_FUNCTION_COUNT = 10
    };
    enum ENTRY_POINT_FUNCTION_TYPE
    {
        VALUE_FUNCTION = 0,
        LEVELED_LIST_FUNCTION = 1,
        ACTIVATE_FUNCTION = 2,
        SPECIAL_FUNCTION = 3,
        ENTRY_POINT_FUNCTION_TYPE_COUNT = 4
    };
    struct EntryPointFunctionInfo
    {
        void(__cdecl* pFunction)(TESObjectREFR*, ENTRY_POINT_FUNCTION_TYPE, unsigned char, void**, void*);  // 00
        char* pFunctionName;                    // 08
        ENTRY_POINT_FUNCTION_TYPE m_eFunctionType;  // 10
    };
    static void ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* reference, ENTRY_POINT_FUNCTION_TYPE type,
                              unsigned char argumentCount, void** arguments, void* data);  // compared: 0x38d1f0
    static EntryPointFunctionInfo ms_kEntryPointFunctionTable[];
};
static_assert(sizeof(Unk38d1f0::EntryPointFunctionInfo) == 0x18, "table entry size");
