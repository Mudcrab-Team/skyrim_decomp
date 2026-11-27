// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiObject, NiAVObject, IsEqual, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, NiFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// ViewPort: GUESS(low)
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once

class NiObject {};
class NiAVObject : public NiObject
{
public:
    bool IsEqual(NiObject* other);

    unsigned char unknown00[0x110];
};

struct NiFrustum
{
    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
};
struct ViewPort
{
    float left;
    float right;
    float top;
    float bottom;
};
class NiCamera : public NiAVObject
{
public:
    bool IsEqual(NiObject* other);

    float worldToCam[4][4];
    NiFrustum viewFrustum;
    float minNearPlaneDist;
    float maxFarNearRatio;
    ViewPort port;
    float lodAdjust;
};
