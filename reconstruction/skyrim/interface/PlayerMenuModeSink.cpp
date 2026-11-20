// PlayerMenuModeSink: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// MenuModeChangeEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerMenuModeSink, ProcessEvent, PlayerReceiver, NotifyMode, mode, currentMode: STANDIN GUESS(medium); event receiver bound at offset 0x2c0, remaining identities inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75ecd0 ProcessEvent
#include "PlayerMenuModeSink.h"
namespace P2073 {
std::int32_t PlayerMenuModeSink::ProcessEvent(const MenuModeChangeEvent* event, void*) {
    if (event->mode) {
        currentMode = 0;
        auto* player = PlayerReceiver::FromMenuModeSink(this);
        player->NotifyMode(false);
    } else {
        currentMode = -1;
    }
    return 0;
}
}
