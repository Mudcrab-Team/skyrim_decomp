// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSSoundOutput, BGSSoundOutput::ApplyDefaults, OutputSettings, kDefaultOutputSettings, values: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) int* __cdecl _errno(void);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

struct OutputSettings
{
    std::uint32_t values[6];
};

extern const OutputSettings kDefaultOutputSettings;

class BGSSoundOutput
{
public:
    static OutputSettings* ApplyDefaults(OutputSettings* settings);  // compared: 0x32b910
};
