// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x32b910 BGSSoundOutput::ApplyDefaults
// Adapted bodies: none
#include "BGSSoundOutput_32b910.h"

OutputSettings* BGSSoundOutput::ApplyDefaults(OutputSettings* settings)
{
    if (!settings) {
        *_errno() = 22;
        _invalid_parameter_noinfo();
    } else {
        *settings = kDefaultOutputSettings;
    }
    return settings;
}
