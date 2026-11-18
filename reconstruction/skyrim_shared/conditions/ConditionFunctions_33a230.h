// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasRefType: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSLocationRefType;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool HasRefType(TESObjectREFR* reference, BGSLocationRefType* type, void*, double* result);
};
