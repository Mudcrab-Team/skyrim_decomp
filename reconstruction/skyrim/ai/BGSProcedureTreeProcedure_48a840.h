// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSProcedureTreeProcedure, BGSProcedureBase, BGSTypedItem, BGSProcedureTreeConditionalItem, IProcedureTreeItem, TESCondition, head, conditions, procedure: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SetProcedure: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct TESConditionItem;
struct TESCondition { TESConditionItem* head; };
class IProcedureTreeItem { public: virtual ~IProcedureTreeItem(); };
class BGSProcedureTreeConditionalItem : public IProcedureTreeItem { public: TESCondition conditions; };
template<class Child, class Parent> class BGSTypedItem : public Parent {};
class BGSProcedureBase { public: virtual ~BGSProcedureBase(); };
class BGSProcedureTreeProcedure : public BGSTypedItem<BGSProcedureTreeProcedure, BGSProcedureTreeConditionalItem> {
public:
 void SetProcedure(BGSProcedureBase* value);
 BGSProcedureBase* procedure;
};
