// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ApplyDefaults, OutputSettings, kDefaultOutputSettings, values: GUESS(low); purpose inferred from the copy and null check.
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
