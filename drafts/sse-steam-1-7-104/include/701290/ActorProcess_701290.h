// Exposure detail: (local target analysis and permitted name/layout references).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: EXE_RTTI
// GetCachedMovementSpeeds: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb); candidate name from AIProcess
// HighProcessData, Movement::MaxSpeeds, Movement::TypeData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// high, currentMovementType, defaultData, speeds, rotateWhileMovingRun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// padding: GUESS(low); unused layout ranges

#pragma once
#include <cstdint>
#include <cstddef>

namespace Movement
{
    struct MaxSpeeds
    {
        float speeds[5][2];
        float rotateWhileMovingRun;
    };
    struct TypeData
    {
        std::uint8_t padding[8];
        MaxSpeeds defaultData;
    };
}
struct HighProcessData
{
    std::uint8_t padding[0xF0];
    Movement::TypeData currentMovementType;
};
class ActorProcess
{
public:
    bool GetCachedMovementSpeeds(Movement::MaxSpeeds& output) const;
    std::uint8_t padding[0x10];
    HighProcessData* high;
};
static_assert(sizeof(Movement::MaxSpeeds) == 0x2C, "speed data size");
static_assert(offsetof(HighProcessData, currentMovementType) == 0xF0, "movement offset");
static_assert(offsetof(ActorProcess, high) == 0x10, "high process offset");
