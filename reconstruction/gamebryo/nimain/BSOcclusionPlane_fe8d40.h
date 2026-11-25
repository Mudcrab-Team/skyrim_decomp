// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// IsOcclusionPlane: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// visibilityState: CRASHLOGGER_PDB(59818@2026.10.24)
// BSOcclusionPlane, CopyFrustumPlanes, BuildFrustumPlanes, NiPoint3 and frustumPlanes: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "NiObject.h"
#include "NiFrustumPlanes_fe8200.h"
class BSOcclusionShape : public NiObject {
public:
    virtual bool IsOcclusionPlane() const = 0;
    unsigned char unknown10[0x30];
    enum { visible = 1, hidden = 2 };
    unsigned int visibilityState;
};
struct BSOcclusionPlane : BSOcclusionShape {
    BSOcclusionPlane();
    ~BSOcclusionPlane() override;
    bool IsOcclusionPlane() const override;
    void BuildFrustumPlanes(const NiPoint3& position);
    void CopyFrustumPlanes(const NiPoint3& position, NiFrustumPlanes& result);
    unsigned char unknown48[8];
    NiFrustumPlanes frustumPlanes;
    unsigned char unknownC0[0x58];
};
static_assert(sizeof(BSOcclusionPlane) == 0x118, "portal plane base layout");
