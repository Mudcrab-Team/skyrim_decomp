// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// NiObject, NiAccumulator, NiCamera, camera: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "NiObject.h"

class NiCamera;

class NiAccumulator : public NiObject
{
public:
    NiAccumulator();
    ~NiAccumulator() override;
    NiCamera* camera;
};
