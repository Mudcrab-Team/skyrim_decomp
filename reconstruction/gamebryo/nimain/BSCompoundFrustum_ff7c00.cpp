// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ProcessOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff7c00 BSCompoundFrustum::ProcessOcclusionShape
#include "BSCompoundFrustum_ff7c00.h"

bool BSCompoundFrustum::ProcessOcclusionShape(BSOcclusionShape* shape)
{
    if (shape->IsOcclusionPlane()) {
        return ProcessPortal(static_cast<BSPortal*>(shape));
    }
    auto* box = static_cast<BSOcclusionBox*>(shape);
    box->UpdateCorners();
    return ProcessMultiBoundShape(box->boundShape);
}
