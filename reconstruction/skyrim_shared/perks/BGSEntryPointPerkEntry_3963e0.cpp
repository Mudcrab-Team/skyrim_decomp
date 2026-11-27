// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x3963e0 BGSEntryPointPerkEntry::ResolveForms_1403378F0
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_3963e0.h"

// Resolves form references in each condition and in the entry point function data.
void BGSEntryPointPerkEntry::ResolveForms_1403378F0(TESFile* a_mod)
{
    for (std::uint32_t i = 0; i < numArgs; ++i) {
        conditions[i].ResolveForms(a_mod);
    }
    if (functionData) {
        functionData->ResolveForms(a_mod);
    }
}
