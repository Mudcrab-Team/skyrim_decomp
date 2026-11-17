// Build: sse-steam-1-7-104; RVA 0x334340; 200 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names, generator representation, and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetRandomPercent: GUESS(low); the static source container and original signature are unverified.
#pragma once

class ConditionFunctions
{
public:
    static bool GetRandomPercent(void*, void*, void*, double* result);
};
