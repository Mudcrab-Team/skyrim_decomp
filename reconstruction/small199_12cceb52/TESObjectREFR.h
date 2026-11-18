// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESObjectREFR: STANDIN EXE_RTTI
// Function68ab50, Function67f1a0, GetInventory, GetReferenceData, CountValue, FindValue: GUESS(low)
#pragma once
#include <cstdint>
class Inventory { public: std::uint64_t CountValue(std::uint32_t); };
class ReferenceData { public: std::uint64_t FindValue(void*); };
class TESObjectREFR { public: Inventory* GetInventory(); ReferenceData* GetReferenceData(); std::uint64_t Function68ab50(std::uint32_t); std::uint64_t Function67f1a0(void*); };
