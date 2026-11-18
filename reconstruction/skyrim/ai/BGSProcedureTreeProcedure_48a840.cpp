// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSProcedureTreeProcedure, BGSProcedureBase, BGSTypedItem, BGSProcedureTreeConditionalItem, IProcedureTreeItem, TESCondition, head, conditions, procedure: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SetProcedure: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x48a840 BGSProcedureTreeProcedure::sub
#include "BGSProcedureTreeProcedure_48a840.h"
void BGSProcedureTreeProcedure::SetProcedure(BGSProcedureBase* value) {
 delete procedure;
 procedure = value;
}
