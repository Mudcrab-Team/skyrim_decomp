// Build: sse-steam-1-7-104; RVA 0x330dd0; 172 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESForm::formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetDisabled: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "../fo4p198c_bound/TESForm.h"
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
