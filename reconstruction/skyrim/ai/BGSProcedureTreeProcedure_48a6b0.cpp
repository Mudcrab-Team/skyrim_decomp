// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned procedure code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x48a6b0 BGSProcedureTreeProcedure::ForwardSlot06
// 0x48a6d0 BGSProcedureTreeProcedure::ForwardSlot07
// 0x48a6f0 BGSProcedureTreeProcedure::ForwardSlot1D
// 0x48a710 BGSProcedureTreeProcedure::ForwardSlot08
// 0x48a7a0 BGSProcedureTreeProcedure::ForwardSlot1B
// 0x48a7c0 BGSProcedureTreeProcedure::ForwardSlot1C
#include "BGSProcedureTreeProcedure_48a6b0.h"

void BGSProcedureTreeProcedure::ForwardSlot06()
{
    return procedure->Slot06();
}

void BGSProcedureTreeProcedure::ForwardSlot07()
{
    return procedure->Slot07();
}

void BGSProcedureTreeProcedure::ForwardSlot1D()
{
    if (procedure) {
        procedure->Slot1D();
    }
}

void BGSProcedureTreeProcedure::ForwardSlot08()
{
    return procedure->Slot08();
}

void BGSProcedureTreeProcedure::ForwardSlot1B()
{
    return procedure->Slot1B();
}

void BGSProcedureTreeProcedure::ForwardSlot1C()
{
    return procedure->Slot1C();
}
