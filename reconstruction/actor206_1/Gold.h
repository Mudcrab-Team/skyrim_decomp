// Gold: STANDIN GUESS(low); receiver identity remains provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2061 {
// Gold, GoldInventory: STANDIN GUESS(low); receiver and callee identity remain provisional.
// GoldExtraList, GetGoldAmount: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); partial declaration, receiver not established.
struct GoldInventory { std::int32_t GoldAmount(); };
struct GoldExtraList : P206Target::ExtraDataListPrefix { GoldInventory* Inventory(); };
class Gold : public P206Target::ActorTargetPrefix<GoldExtraList> { public: std::int32_t GetGoldAmount(bool noInit); };
}
