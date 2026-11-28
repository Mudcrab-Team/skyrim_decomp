// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x690be0 Actor690be0::GetCollisionFilterInfo
// Adapted bodies: none
#include "Actor690be0.h"

// Queries the actor's process controller for collision filter info, returning 0 if unavailable.
// The community prototype has no return value; here the filter info is returned by value.
FilterInfo690be0 Actor690be0::GetCollisionFilterInfo()
{
    if (process != nullptr) {
        Controller690be0* controller = process->GetController();
        if (controller != nullptr) {
            std::uint32_t filter;
            controller->GetCollisionFilterInfo(filter);
            return FilterInfo690be0(filter);
        }
    }
    return FilterInfo690be0(0);
}
