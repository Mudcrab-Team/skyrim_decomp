// AIProcess207Pass: STANDIN GUESS(low); partial target-bound receiver/callee view, no complete layout or ownership asserted.
// Origin: original reconstruction; cited adapted declarations retain complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md.
// Partial declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, AIProcess.h, HighProcessData.h, MiddleHighProcessData.h, InventoryEntryData.h, BSPointerHandle.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7023a0 P2071::AIProcess207Pass::SetHighFloat
// 0x6e8370 P2071::AIProcess207Pass::UpdateTimeBits
#include "AIProcess207Pass.h"
namespace P2071 {
void AIProcess207Pass::SetHighFloat(float value) {
    if (high) high->unknown1e4 = value;
}
void AIProcess207Pass::UpdateTimeBits() {
    unknown48 = TimeFloat;
    unknown4c = ((TimeHigh << 4) | TimeMiddle) << 9 | static_cast<std::int32_t>(TimeLow);
}
}
