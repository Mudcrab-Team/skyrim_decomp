// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ProcessOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// ProcessPortal, ProcessMultiBoundShape, UpdateCorners, boundShape, BSPortal, BSOcclusionBox, BSOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// BSOcclusionPlane, IsOcclusionPlane: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
#pragma once

#include "declarations/NiObject.h"

class BSMultiBoundShape;

class BSOcclusionShape : public NiObject
{
public:
    virtual bool IsOcclusionPlane() const = 0;
};
class BSOcclusionPlane : public BSOcclusionShape {};
class BSPortal : public BSOcclusionPlane {};
class BSOcclusionBox : public BSOcclusionShape
{
public:
    void UpdateCorners();
    unsigned char unknown10[0x188];
    BSMultiBoundShape* boundShape;
};

class BSCompoundFrustum
{
public:
    bool ProcessOcclusionShape(BSOcclusionShape* shape);
private:
    bool ProcessPortal(BSPortal* portal);
    bool ProcessMultiBoundShape(BSMultiBoundShape* shape);
};
