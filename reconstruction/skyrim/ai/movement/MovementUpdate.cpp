// MovementUpdate: STANDIN GUESS(low); receiver identity is provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6a9570 P2061::MovementUpdate::Function6a9570
#include "MovementUpdate.h"
namespace P2061 {
int MovementUpdate::Function6a9570(MovementArgument* argument) { if (movementController) movementController->Apply(argument->value); return 1; }
}
