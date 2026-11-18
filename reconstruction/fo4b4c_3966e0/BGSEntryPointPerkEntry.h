// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/B/BGSPerkEntry.h, BGSEntryPointPerkEntry.h and BGSEntryPointFunctionData.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); virtual return type and names are inferred from target accesses.
#pragma once
class TESFile; class BGSPerk;
class BGSEntryPointFunctionData { public: virtual ~BGSEntryPointFunctionData(); virtual int GetType() const; virtual bool LoadFunctionData(TESFile*); virtual void ResolveForms(TESFile*); virtual void Unk04(); virtual unsigned short GetID(); virtual void SetPerk(BGSPerk*); };
class BGSPerkEntry { public: virtual ~BGSPerkEntry(); struct Header { unsigned char rank, priority; unsigned short unk2; unsigned int unk4; } header; };
class BGSEntryPointPerkEntry : public BGSPerkEntry { public: struct EntryData { unsigned char entryPoint, function, numArgs, unk3; unsigned int unk4; } entryData; BGSEntryPointFunctionData* functionData; unsigned short GetID() const; };
