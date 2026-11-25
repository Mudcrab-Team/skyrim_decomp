// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, SetCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCamera, NiFrustumPlanes, Set, world, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "generated/crashlogger_pdb/types/NiFrustum.h"
#include "generated/crashlogger_pdb/types/NiPoint3.h"
#include "generated/crashlogger_pdb/types/NiMatrix3.h"

struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};

class NiCamera
{
public:
    unsigned char unknown00[0x7c];
    NiTransform world;
    unsigned char unknownB0[0xa0];
    NiFrustum viewFrustum;
};

class NiFrustumPlanes
{
public:
    void Set(const NiFrustum& frustum, const NiTransform& transform);
private:
    unsigned char unknown00[0x70];
};

class BSCompoundFrustum
{
public:
    void SetCamera(NiCamera* newCamera);
private:
    unsigned char unknown00[0x30];
    NiFrustumPlanes viewFrustum;
    NiPoint3 viewPosition;
    NiCamera* camera;
    unsigned int freePlane;
    unsigned int freeOp;
    unsigned int firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};
