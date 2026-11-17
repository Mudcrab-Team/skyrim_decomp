// Build: sse-steam-1-7-104; RVA 0x3308c0; 173 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// ActorValueOwner::GetActorValue and actor layout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted in ValueActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetActorValue: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetActorValue(TESObjectREFR* reference, void* actorValueParameter, void*, double* result);
};
