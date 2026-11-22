// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetDistance: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x330290 Condition::GetDistance
#include "ConditionFunctions_330290.h"
#include "skyrim_shared/forms/TESForm_1467c0.h"
extern float DistanceBetween(TESForm*, TESForm*, bool, bool);
extern void* conditionLogger;
extern const char distanceLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static bool TestBit(unsigned a_flags, unsigned a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}
bool ConditionFunctions::GetDistance(TESForm* reference, TESForm* other, void*, double* result)
{
    if (reference && other) {
        bool special = TestBit(reference->formFlags, 14) || TestBit(other->formFlags, 14);
        *result = DistanceBetween(reference, other, true, special);
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, distanceLogFormat, *result);
    return true;
}
