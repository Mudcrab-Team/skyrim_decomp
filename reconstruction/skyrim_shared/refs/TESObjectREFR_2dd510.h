/*
 * TESObjectREFR: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x2dd510 21 bytes; RVA 0x2dd530 30 bytes; RVA 0x2dd560 30 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared functions and callees have inferred signatures and unverified ownership.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
// TESObjectREFR: STANDIN EXE_RTTI
// RelatedA, RelatedB, GetRelatedA, GetRelatedB, First, Second, Third, Function2dd510, Function2dd530, Function2dd560: GUESS(low)
#pragma once

class TESObjectREFR;
class RelatedA { public: void* First(); };
class RelatedB { public: void* Second(TESObjectREFR*); void* Third(TESObjectREFR*); };
class TESObjectREFR {
public:
    void* Function2dd510();
    void* Function2dd530();
    void* Function2dd560();
    RelatedA* GetRelatedA();
    RelatedB* GetRelatedB();
};
