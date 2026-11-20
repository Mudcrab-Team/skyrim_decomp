// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// MenuTopicManager members and actor/form slots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from public headers.
// names: GUESS(low); names, layouts and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::IsInDialogueWithPlayer: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once
class TESObjectREFR;
class ConditionFunctions {
public:
    static bool IsInDialogueWithPlayer(TESObjectREFR* reference, void*, void*, double* result);
};
