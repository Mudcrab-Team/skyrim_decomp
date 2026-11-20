// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// BGSProjectile, BGSProjectile::ClearData: GUESS(low)
// BGSProjectile fields: STANDIN GUESS(low)
// Model: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); TESModel virtual slots.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class Model { public: virtual ~Model() = default; virtual void InitializeDataComponent(); virtual void ClearDataComponent(); };
class BGSProjectile {
public: void ClearData();
private: std::uint8_t pad[0x108]; Model muzzleFlashModel;
};
