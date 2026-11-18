// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInCurrentLoc: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSLocation;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetInCurrentLoc(TESObjectREFR* reference, BGSLocation* location, void*, double* result);
};
