// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiAVObject, CopyMembers, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, NiFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// worldTranslate, ViewPort: GUESS(low)
#pragma once

class NiCloningProcess;
class NiAVObject
{
public:
    void CopyMembers(NiAVObject* destination, NiCloningProcess& cloning);

    unsigned char unknown00[0xa0];
    struct {
        float x;
        float y;
        float z;
    } worldTranslate;
    unsigned char unknownAC[0x64];
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
    void CopyMembers(NiCamera* destination, NiCloningProcess& cloning);

    float worldToCam[4][4];
    NiFrustum viewFrustum;
    float minNearPlaneDist;
    float maxFarNearRatio;
    ViewPort port;
    float lodAdjust;
};
