// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// ActorValueOwner::GetActorValue and actor layout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted in ValueActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetActorValue: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetActorValue(TESObjectREFR* reference, void* actorValueParameter, void*, double* result);
};
