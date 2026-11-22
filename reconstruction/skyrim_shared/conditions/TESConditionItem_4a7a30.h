// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESConditionItem::Copy: SIBLING(fo4-private@1b765c70, author-permission); adapted member copy.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:91
// TESConditionItem, CONDITION_ITEM_DATA, FUNCTION_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESCondition.h.
// Copy, TESParameters, TESForm: GUESS(low); names and signature remain unverified.
// TestBit: GUESS(low); flag bit test by bit index taking the word by value
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESForm;
// TESGlobal, TESGlobal::value: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the float at 0x34 is read
struct TESGlobal { std::uint8_t unk00[0x34]; float value; };
struct FUNCTION_DATA { std::uint16_t function, pad02; std::uint32_t pad04; void* params[2]; };
struct CONDITION_ITEM_DATA {
    union { TESGlobal* global; float value; } comparisonValue;
    std::uint32_t runOnRef;
    std::uint32_t dataID;
    FUNCTION_DATA functionData;
    std::int8_t flags; std::uint8_t object;
};
class TESParameters { public: static void Copy(const FUNCTION_DATA& from, FUNCTION_DATA& to); };
class TESConditionItem {
public:
    void Copy(const TESConditionItem* from, TESForm* owner);
    // GetComparisonValue: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
    float GetComparisonValue() const;
    TESConditionItem* next;
    CONDITION_ITEM_DATA data;
};
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit) { return ((a_flags >> a_bit) & 1) != 0; }
