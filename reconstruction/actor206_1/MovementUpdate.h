// MovementUpdate: STANDIN GUESS(low); receiver identity is provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2061 {
// MovementUpdate, MovementArgument, MovementController: STANDIN GUESS(low); types and semantics provisional.
struct MovementArgument { std::uint8_t unknown00[0x10]; std::uint8_t value; };
struct MovementController { void Apply(std::uint8_t); };
class MovementUpdate : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, P206Target::AIProcess, MovementController> {
public: int Function6a9570(MovementArgument* argument);
};
}
