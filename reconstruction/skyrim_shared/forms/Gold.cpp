// Gold: STANDIN GUESS(low); receiver identity remains provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x68be50 P2061::Gold::GetGoldAmount
#include "Gold.h"
namespace P2061 {
std::int32_t Gold::GetGoldAmount(bool) { auto* inventory = reference.extraList.Inventory(); if (inventory) return inventory->GoldAmount(); return 0; }
}
