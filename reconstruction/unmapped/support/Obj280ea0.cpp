// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x280ea0 Obj280ea0::Function280ea0
// Adapted bodies: none
#include "Obj280ea0.h"

// Sets or clears a flag bit, recursively clearing the mutually exclusive bit among {0, 2}.
void Obj280ea0::Function280ea0(std::int32_t a_bit, bool a_set)
{
    if (a_set) {
        flags |= static_cast<std::uint8_t>(1 << a_bit);
        if (a_bit == 0 || a_bit == 2) {
            for (std::int32_t i = 0; i < 4; ++i) {
                if ((i == 0 || i == 2) && i != a_bit) {
                    Function280ea0(i, false);
                }
            }
        }
    } else {
        flags &= static_cast<std::uint8_t>(~(1 << a_bit));
    }
}
