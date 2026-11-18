// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsEditorLocAlias: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetIsEditorLocAlias(TESObjectREFR* reference, unsigned int alias, void*, double* result);
};
