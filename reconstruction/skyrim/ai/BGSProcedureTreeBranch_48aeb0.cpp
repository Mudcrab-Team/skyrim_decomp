// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x48aeb0 BGSProcedureTreeBranch::Func2_140429090
// Adapted bodies: none
#include "BGSProcedureTreeBranch_48aeb0.h"

// Resolves form references in this branch's condition and recursively in each child item.
void BGSProcedureTreeBranch::Func2_140429090(TESFile* a_mod)
{
    condition.ResolveForms(a_mod);
    std::uint32_t count = conditions.size;
    for (std::uint32_t i = 0; i < count; ++i) {
        conditions.data[i]->Func2_140429090(a_mod);
    }
}
