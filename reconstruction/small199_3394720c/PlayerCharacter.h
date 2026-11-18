// Inferred names: GUESS(low)
// Origin: declaration adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter, GetItemCount, TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Inventory, GetInventory, CountItem: GUESS(low)
#pragma once
#include <cstdint>
class TESBoundObject;
class Inventory { public: std::int32_t CountItem(TESBoundObject*); };
class PlayerCharacter { public: Inventory* GetInventory(); std::int32_t GetItemCount(TESBoundObject*); };
