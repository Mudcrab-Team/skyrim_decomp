// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum, AddOcclusionShapeIfVisible, ProcessPortal, AddPortal, AddOcclusionBox, ProcessMultiBoundShape, BSOcclusionShape, BSPortal, BSOcclusionBox, visibilityState, UpdateCorners and boundShape: CRASHLOGGER_PDB(59818@2026.10.24)
// visibility constants: GUESS(low)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff7f50 BSCompoundFrustum::AddOcclusionShapeIfVisible
// CI hash: 0xff7f50 ?AddOcclusionShapeIfVisible@BSCompoundFrustum@@QEAAXPEAVBSOcclusionShape@@PEAU1@@Z
#include "BSCompoundFrustum_ff7f50.h"

void BSCompoundFrustum::AddOcclusionShapeIfVisible(BSOcclusionShape* shape, BSCompoundFrustum* test)
{
    if (shape->IsOcclusionPlane()) {
        auto* portal = static_cast<BSPortal*>(shape);
        if (portal->visibilityState == BSOcclusionShape::visible && (!test || test->ProcessPortal(portal))) {
            AddPortal(portal);
        }
    } else {
        auto* box = static_cast<BSOcclusionBox*>(shape);
        bool visible = false;
        box->UpdateCorners();
        if (!test || test->ProcessMultiBoundShape(box->boundShape)) {
            visible = AddOcclusionBox(box);
        }
        box->visibilityState = visible ? BSOcclusionShape::visible : BSOcclusionShape::hidden;
    }
}
