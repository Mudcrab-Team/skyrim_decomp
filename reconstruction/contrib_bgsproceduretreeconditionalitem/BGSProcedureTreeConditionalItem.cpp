// Code origin: Unk_01, Unk_02 and Unk_10 bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x48a330 BGSProcedureTreeConditionalItem::Unk_02
// 0x48a310 BGSProcedureTreeConditionalItem::Unk_01
// 0x48a3b0 BGSProcedureTreeConditionalItem::Unk_10
#include "BGSProcedureTreeConditionalItem.h"
void BGSProcedureTreeConditionalItem::Unk_02() { conditions.Unk4a6940(); }
void BGSProcedureTreeConditionalItem::Unk_01(BGSProcedureTreeConditionalItem* a_other) { conditions.Unk4a6ab0(&a_other->conditions); }
bool BGSProcedureTreeConditionalItem::Unk_10(IProcedureTreeItem* a_other)
{
    void** other = a_other->Unk_05();
    void** self = Unk_06();
    return *self == *other;
}
