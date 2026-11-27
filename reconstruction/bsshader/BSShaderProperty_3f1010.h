// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, Clear: CRASHLOGGER_PDB(59818@2026.10.24)
// PassEntry, nextEntry: GUESS(low)
#pragma once

class BSShaderProperty
{
public:
    struct RenderPassArray
    {
        struct PassEntry
        {
            ~PassEntry();
            unsigned char unrecovered000[0x40];
            PassEntry* nextEntry;
        };

        void Clear();
        PassEntry* head;
    };
};
