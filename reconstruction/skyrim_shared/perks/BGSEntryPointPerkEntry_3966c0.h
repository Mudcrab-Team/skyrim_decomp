// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// BGSEntryPointPerkEntry, BGSEntryPointPerkEntry::SetParent: GUESS(low)
// BGSEntryPointPerkEntry fields: STANDIN GUESS(low)
// Supporting types: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order from the pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class Perk; class File;
class FunctionData { public: virtual ~FunctionData() = default; virtual int GetType() const; virtual bool LoadFunctionData(File*); virtual void ResolveForms(File*); virtual void Unk04(); virtual void Unk05(); virtual void SetPerk(Perk*); };
class BGSEntryPointPerkEntry {
public: void SetParent(Perk* value);
private: std::uint8_t pad[0x18]; FunctionData* functionData; std::uint8_t gap[8]; Perk* parent;
};
