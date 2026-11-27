// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x48b0b0 BGSProcedureTreeBranch::Func12_140429280
// Adapted bodies: none
#include "BGSProcedureTreeBranch_48b0b0.h"

// Visits this branch and recursively visits each child item until the visitor requests a stop.
void BGSProcedureTreeBranch::Func12_140429280(ProcedureTreeVisitor* a_visitor)
{
    a_visitor->Visit(this);
    std::uint32_t count = conditions.size;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (a_visitor->ShouldStop()) {
            break;
        }
        conditions.data[i]->Func12_140429280(a_visitor);
    }
}
