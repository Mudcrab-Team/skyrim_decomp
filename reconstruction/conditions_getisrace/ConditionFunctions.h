// Build: sse-steam-1-7-104; RVA 0x333790; 147 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectREFR, TESNPC, TESRace and form fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsRace: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetIsRace(TESObjectREFR* reference, TESForm* parameter, void*, double* result);
};
