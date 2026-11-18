// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInCurrentLocAlias: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetInCurrentLocAlias(TESObjectREFR* reference, unsigned int alias, void*, double* result);
};
