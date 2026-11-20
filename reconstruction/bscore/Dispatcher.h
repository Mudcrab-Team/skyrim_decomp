// Dispatcher: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Character: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// DispatchPayload, Dispatcher, GetDispatcher, Submit, DispatchCharacterValue: STANDIN GUESS(low); payload and free-function ownership inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
class Character;
struct DispatchPayload { Character* character; std::uint32_t value; };
class Dispatcher { public: void Submit(const DispatchPayload*); };
Dispatcher* GetDispatcher();
void DispatchCharacterValue(Character*, std::uint32_t);
}
