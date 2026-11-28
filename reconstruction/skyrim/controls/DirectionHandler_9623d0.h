// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// DirectionHandler, UpdateRepeat: CRASHLOGGER_PDB(59818@2026.10.24)
// nextRepeatTime, maxDelay, minDelay, repeatCount, maxRepeats, unk00, unk1C: GUESS(low)
#pragma once

#include <cstdint>

class DirectionHandler
{
public:
    bool UpdateRepeat(float time);

    std::uint8_t  unk00[0x10];     // 00
    float         nextRepeatTime;  // 10
    float         maxDelay;        // 14
    float         minDelay;        // 18
    std::uint32_t unk1C;           // 1C
    std::uint32_t repeatCount;     // 20
    std::uint32_t maxRepeats;      // 24
};
static_assert(sizeof(DirectionHandler) == 0x28, "DirectionHandler size");
