// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xef7ff0 NiTimeController::RegisterStreamables
// 0xef8320 NiTimeController::Start
// 0xef8340 NiTimeController::Stop
// 0xef86a0 NiTimeController::CountChain
#include "NiTimeController_ef7ff0.h"

#include <limits>

namespace
{
constexpr std::uint16_t active = 1u << 3;
constexpr std::uint16_t appInitTime = 1u;
constexpr float invalidTime = -std::numeric_limits<float>::max();
}

bool NiTimeController::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiObject::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (next) {
        next->RegisterStreamables(stream);
    }
    return true;
}

void NiTimeController::Start(float time)
{
    flags |= active;
    lastTime = invalidTime;
    if (flags & appInitTime) {
        startTime = time;
    }
}

void NiTimeController::Stop()
{
    lastTime = invalidTime;
    flags &= ~active;
    if (flags & appInitTime) {
        startTime = invalidTime;
    }
}

std::uint32_t NiTimeController::CountChain(const NiTimeController* controller)
{
    std::uint32_t count = 0;
    while (controller) {
        controller = controller->next;
        ++count;
    }
    return count;
}
