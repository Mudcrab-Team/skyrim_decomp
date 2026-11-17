// Build: sse-steam-1-7-104; RVA 0x3316b0; 129 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectREFR::IsDead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declaration in DeadActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetDead: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;

class ConditionFunctions
{
public:
    static bool GetDead(TESForm* reference, void*, void*, double* result);
};
