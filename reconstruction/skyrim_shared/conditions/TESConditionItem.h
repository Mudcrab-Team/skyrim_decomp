// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESConditionItem::Copy: SIBLING(fo4-private@1b765c70, author-permission); adapted member copy.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:91
// TESConditionItem, CONDITION_ITEM_DATA, FUNCTION_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESCondition.h.
// Copy, TESParameters, TESForm: GUESS(low); names and signature remain unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESForm;
struct FUNCTION_DATA { std::uint16_t function, pad02; std::uint32_t pad04; void* params[2]; };
struct CONDITION_ITEM_DATA {
    union { void* global; float value; } comparisonValue;
    std::uint32_t runOnRef;
    std::uint32_t dataID;
    FUNCTION_DATA functionData;
    std::uint8_t flags, object;
};
class TESParameters { public: static void Copy(const FUNCTION_DATA& from, FUNCTION_DATA& to); };
class TESConditionItem {
public:
    void Copy(const TESConditionItem* from, TESForm* owner);
    TESConditionItem* next;
    CONDITION_ITEM_DATA data;
};
