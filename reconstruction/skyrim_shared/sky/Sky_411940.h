// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sky, Sky::Function411940, Sky::flags1DC: GUESS(low)
// Sky::Function411940: CRASHLOGGER_PDB(59818@2026.10.24); size only
#pragma once

#include <cstdint>
#include <cstddef>

class Sky
{
public:
    void Function411940(bool a_set);  // compared: 0x411940

    std::uint8_t pad00[0x1DC];
    std::uint32_t flags1DC;  // 0x1DC
};
