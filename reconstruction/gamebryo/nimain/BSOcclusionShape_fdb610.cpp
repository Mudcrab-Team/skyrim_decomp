// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSOcclusionShape, CopyTransformTo: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfdb610 BSOcclusionShape::CopyTransformTo
#include "BSOcclusionShape_fdb610.h"

void BSOcclusionShape::CopyTransformTo(BSOcclusionShape& destination) const
{
    destination.translation.x = translation.x;
    destination.translation.y = translation.y;
    destination.translation.z = translation.z;
    destination.updateFacesOrVertices = true;
    destination.rotation = rotation;
    destination.visibilityState = visibilityState;
}
