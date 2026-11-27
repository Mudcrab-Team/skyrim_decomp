// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// BSCompoundFrustum, AddOcclusionShapeIfVisible, ProcessPortal, AddPortal, AddOcclusionBox, ProcessMultiBoundShape, BSOcclusionShape, BSPortal, BSOcclusionBox, visibilityState, UpdateCorners and boundShape: CRASHLOGGER_PDB(59818@2026.10.24)
// visibility constants: GUESS(low)
// IsOcclusionPlane: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
#pragma once

#include "BSCompoundFrustum_ff72a0.h"
#include "BSPortal_fe9f00.h"

class BSOcclusionBox : public BSOcclusionShape {
public:
    void UpdateCorners();
    unsigned char unknown48[0x150];
    BSMultiBoundShape* boundShape;
};
static_assert(sizeof(struct BSCompoundFrustum) == 0xc8, "BSCompoundFrustum layout");
