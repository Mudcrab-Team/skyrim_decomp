// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed.
// Code origin: Stamped as a twin of matched 0x82ce50 (skyrim/ai/combat/CombatInventoryItem): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Owner15993e0: GUESS(low) STANDIN
#pragma once
#include "CombatInventoryItem.h"

class Owner15993e0: public CombatObject { public: enum class TYPE { kNone }; virtual float GetMinRange(); virtual float GetMaxRange(); virtual float GetOptimalRange(); virtual float GetEquipRange(); virtual TYPE GetType(); virtual TYPE GetEquipType(unsigned int); };

