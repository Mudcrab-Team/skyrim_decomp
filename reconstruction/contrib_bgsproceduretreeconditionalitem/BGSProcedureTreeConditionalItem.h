// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed
// names: GUESS(low); names and signatures are hypotheses.
// BGSProcedureTreeConditionalItem, TESCondition: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BGSProcedureTreeConditionalItem.h and include/RE/T/TESCondition.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSProcedureTreeConditionalItem::Unk_01, Unk_02, Unk_10: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// IProcedureTreeItem::Unk_05, Unk_06: GUESS(low); virtual slots at byte offsets 0x28 and 0x30, each returns a pointer to a pointer
// TESCondition::Unk4a6940, TESCondition::Unk4a6ab0: GUESS(low); addresses 0x4a6940 and 0x4a6ab0, called on the member at offset 0x8
#pragma once
class TESFile { public: void NextChunk(); };
class IProcedureTreeItem { public: virtual ~IProcedureTreeItem(); virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04(); virtual void** Unk_05(); virtual void** Unk_06(); };
class TESCondition { public: void LoadCompact(TESFile*); void Unk4a6940(); void Unk4a6ab0(TESCondition* a_other); void* head; };
class BGSProcedureTreeConditionalItem : public IProcedureTreeItem { public: void Load(TESFile*); void Unk_02() override; virtual void Unk_01(BGSProcedureTreeConditionalItem* a_other); virtual bool Unk_10(IProcedureTreeItem* a_other); TESCondition conditions; };
