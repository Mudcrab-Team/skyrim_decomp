// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSRenderPass, SetLights, BSLight, numLights, sceneLights: CRASHLOGGER_PDB(59818@2026.10.24)
// maxLights: GUESS(low)
#pragma once

struct BSLight;
struct BSRenderPass
{
    enum { maxLights = 16 };
    void SetLights(unsigned char count, BSLight** lights);

    unsigned char unrecovered000[0x1F];
    unsigned char numLights;
    unsigned char unrecovered020[0x18];
    BSLight** sceneLights;
};
