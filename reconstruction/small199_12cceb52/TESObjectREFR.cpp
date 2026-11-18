// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// 0x68ab50 TESObjectREFR::sub
// 0x67f1a0 TESObjectREFR::sub
#include "TESObjectREFR.h"
std::uint64_t TESObjectREFR::Function68ab50(std::uint32_t value) { Inventory* data = GetInventory(); return data ? data->CountValue(value) : 0; }
std::uint64_t TESObjectREFR::Function67f1a0(void* value) { ReferenceData* data = GetReferenceData(); return data ? data->FindValue(value) : 0; }
