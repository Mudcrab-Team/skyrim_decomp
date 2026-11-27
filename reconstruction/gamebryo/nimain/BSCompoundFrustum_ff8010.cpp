// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xff8010 BSCompoundFrustum::AddOcclusionShapeToGroup
// CI hash: 0xff8010 ?AddOcclusionShapeToGroup@BSCompoundFrustum@@QEAAXPEAUBSOcclusionShape@@PEBXAEA_N@Z
#include "BSCompoundFrustum_ff8010.h"

void BSCompoundFrustum::AddOcclusionShapeToGroup(BSOcclusionShape* shape, const void* view, bool& first)
{
    if (shape->methods->IsPlane(shape)) {
        if (shape->state == 1 || (shape->state == 0 && shape->IsPotentiallyVisible(view, camera->position))) {
            if (first) {
                StartGroupIntersection();
                first = false;
            }
            AddPortal(shape);
        }
    } else {
        auto* box = static_cast<BSOcclusionBox*>(shape);
        bool added = false;
        if (shape->state == 1 || (shape->state == 0 && box->IsPotentiallyVisible(camera, view))) {
            if (first)
                StartGroupIntersection();
            int previous = freeOp;
            added = AddOcclusionBox(box);
            if (first) {
                if (previous == freeOp)
                    --freeOp;
                else
                    first = false;
            }
        }
        box->state = added ? 1 : 2;
    }
}
