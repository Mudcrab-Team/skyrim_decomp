// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// BGSProcedureTreeConditionalItem::Load: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSProcedureTree.cpp:58
// BGSProcedureTreeConditionalItem, TESCondition: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BGSProcedureTreeConditionalItem.h and include/RE/T/TESCondition.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESFile { public: void NextChunk(); };
class IProcedureTreeItem { public: virtual ~IProcedureTreeItem(); };
class TESCondition { public: void LoadCompact(TESFile*); void* head; };
class BGSProcedureTreeConditionalItem : public IProcedureTreeItem { public: void Load(TESFile*); TESCondition conditions; };
