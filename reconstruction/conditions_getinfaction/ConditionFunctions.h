// Build: sse-steam-1-7-104; RVA 0x3339f0; 240 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Actor::IsInFaction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); slot declaration in FactionActor.h.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in FactionActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInFaction: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetInFaction(TESObjectREFR* reference, TESForm* parameter, void*, double* result);
};
