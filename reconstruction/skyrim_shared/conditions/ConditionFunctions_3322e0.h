// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStage: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESObjectREFR;
class TESQuest;

class ConditionFunctions
{
public:
    static bool GetStage(TESObjectREFR*, TESQuest* quest, void*, double* result);
};
