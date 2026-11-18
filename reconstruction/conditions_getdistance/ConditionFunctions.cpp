// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetDistance: GUESS(low); the static source container and original signature are unverified.
// 0x330290 Condition::GetDistance
#include "ConditionFunctions.h"
#include "../fo4p198c_bound/TESForm.h"
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
