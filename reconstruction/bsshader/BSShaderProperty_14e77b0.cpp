// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14e77b0 BSShaderProperty::SetLightState
// Adapted bodies: none
#include "BSShaderProperty_14e77b0.h"

void BSShaderProperty::SetLightState(int a_state)
{
    BSShaderPropertyLightData* data = lightData;
    if (a_state == 0xFFFF) {
        if (data && data->ClearLights()) {
            lastRenderPassState = 0x7FFFFFFF;
        }
    } else if (data) {
        data->EnableLight(a_state - 1);
    }
}
