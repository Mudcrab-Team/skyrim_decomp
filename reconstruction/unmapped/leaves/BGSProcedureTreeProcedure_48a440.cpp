// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x48a440 BGSProcedureTreeProcedure::~BGSProcedureTreeProcedure
// Adapted bodies: none
#include "BGSProcedureTreeProcedure_48a440.h"

BGSProcedureTreeProcedure::~BGSProcedureTreeProcedure()
{
    delete child;
}
