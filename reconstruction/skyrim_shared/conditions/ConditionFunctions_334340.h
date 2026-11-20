// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names, generator representation, and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetRandomPercent: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once

class ConditionFunctions
{
public:
    static bool GetRandomPercent(void*, void*, void*, double* result);
};
