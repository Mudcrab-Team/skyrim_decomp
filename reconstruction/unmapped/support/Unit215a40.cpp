// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x215a40 Unit215a40::ComputeValue215a40
// Adapted bodies: none
#include "Unit215a40.h"

// PDB: the CrashLogger PDB prototype returns unsigned int; the signed type here follows the subtraction of signed penalties.
// Walks to the last node when no override is set and subtracts a kind-dependent penalty from g_baseValue215a40.
std::int32_t Unit215a40::ComputeValue215a40()
{
    std::int32_t result = g_baseValue215a40;
    if (!g_manager215a40->overridePtr) {
        Node215a40* node = g_manager215a40->GetFirstNode();
        while (node) {
            if (!node->GetNext(1)) {
                break;
            }
            node = node->GetNext(1);
        }
        if (node) {
            const std::int32_t penalty = (node->kind == 0x3C) ? g_altPenalty215a40 : g_defaultPenalty215a40;
            result -= penalty;
        }
    }
    return result;
}
