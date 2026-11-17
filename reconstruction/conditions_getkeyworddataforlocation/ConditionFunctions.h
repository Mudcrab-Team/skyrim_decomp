// Build: sse-steam-1-7-104; RVA 0x33ae20; 111 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetKeywordDataForLocation: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSKeyword;
class BGSLocation;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetKeywordDataForLocation(TESObjectREFR*, BGSLocation* location, BGSKeyword* keyword, double* result);
};
