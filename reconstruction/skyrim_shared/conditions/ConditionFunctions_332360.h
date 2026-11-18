// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStageDone: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESObjectREFR;
class TESQuest;

class ConditionFunctions
{
public:
    static bool GetStageDone(TESObjectREFR*, TESQuest* quest, unsigned short stage, double* result);
};
