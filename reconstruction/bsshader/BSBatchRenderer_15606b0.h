// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, InitSDM: CRASHLOGGER_PDB(59818@2026.10.24)
// groupState, groupIndex, nextGroupState: GUESS(low)
#pragma once

class BSBatchRenderer
{
public:
    static void InitSDM();

    static void* groupState;
    static unsigned int groupIndex;
    static void* nextGroupState;
};
