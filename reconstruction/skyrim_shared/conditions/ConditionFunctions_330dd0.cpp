// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm::formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetDisabled: GUESS(low); the static source container and original signature are unverified.
// 0x330dd0 Condition::GetDisabled
#include "ConditionFunctions_330dd0.h"
#include "../forms/TESForm_1467c0.h"
struct DisabledState { void* vtable; unsigned char flags; };
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static inline bool TestBit(unsigned int a_flags, unsigned int a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}
extern bool IsEnabledByParent(TESForm*);
extern bool IsReferenceDisabled(TESForm*);
extern void* conditionLogger;
extern const char disabledLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetDisabled(TESForm* reference, DisabledState* state, void*, double* result)
{
    if (reference) {
        *result = 0.0;
        if ((TestBit(reference->formFlags, 11) && !IsEnabledByParent(reference)) || IsReferenceDisabled(reference)) *result = 1.0;
    } else if (state) *result = static_cast<unsigned char>(state->flags & 1);
    if (conditionLoggingEnabled) LogCondition(conditionLogger, disabledLogFormat, *result);
    return true;
}
