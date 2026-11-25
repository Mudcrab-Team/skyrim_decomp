// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x48cf60 BGSProcedureTreeProcedure::`scalar deleting destructor'
// Adapted bodies: none
#include "BGSProcedureTreeProcedure_48cf60.h"

// Defined here so the deleting destructor is emitted beside the vftable.
BGSProcedureTreeProcedure::~BGSProcedureTreeProcedure()
{
    delete child;
}
