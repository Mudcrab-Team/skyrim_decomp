// Source exposure: binary-analysis (authorized pinned-image observations).
// Code origin: original; observed declarations and explicitly uncertain names.
// SPDX-License-Identifier: CC0-1.0
// QueuedTempEffect, QueuedTempEffect::Function194c70: GUESS(low) STANDIN; prepared inventory owner is uncorroborated.
// unknown, state, stateMessage: GUESS(low) STANDIN; observed field and constant-message reference, descriptive names only.
// strcpy_s: OBSERVED; named import in the pinned image.
#pragma once
#include <cstdint>
#include <cstddef>
extern "C" __declspec(dllimport) int __cdecl strcpy_s(char*, std::size_t, const char*);
extern const char stateMessage[];
class QueuedTempEffect {
public:
    std::uint8_t unknown[0xc];
    std::uint32_t state;
    bool Function194c70(char* buffer, std::uint32_t capacity); // compared: 0x194c70
};
static_assert(offsetof(QueuedTempEffect, state) == 0xc, "observed state field offset");
