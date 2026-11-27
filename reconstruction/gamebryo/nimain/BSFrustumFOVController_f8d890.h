// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original reconstruction from the contributor-owned image.
// BSFrustumFOVController: EXE_RTTI
// NiCamera and view frustum layout: CRASHLOGGER_PDB(59818@2026.10.24)
// GetCameraFOV, target, right: GUESS(low)
#pragma once

struct NiCamera { unsigned char unrecovered00[0x154]; float right; };
struct BSFrustumFOVController {
    unsigned char unrecovered00[0x38];
    NiCamera* target;
    void GetCameraFOV(float& value);
};
