// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x21ac70 BipedAnim21ac70::CountActiveSlots
// Adapted bodies: none
#include "BipedAnim21ac70.h"

// Count how many of the eight biped slots currently hold an item.
std::uint8_t BipedAnim21ac70::CountActiveSlots() const
{
    std::uint8_t count = 0;
    for (std::uint32_t i = 0; i < 8; ++i)
    {
        if (slots[i].item)
        {
            ++count;
        }
    }
    return count;
}
