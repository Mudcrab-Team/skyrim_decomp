// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: NiGeometry::UpdateWorldBound follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometry.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometry.cpp:103
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf0c600 NiGeometry::UpdateWorldBound
#include "NiGeometry_f0c600.h"

#include <cstring>

namespace
{
    bool TestBit(std::uint32_t flags, unsigned int bit)
    {
        return ((flags >> bit) & 1U) != 0;
    }
}

void NiGeometry::UpdateWorldBound()
{
    NiBound& bound = worldBound;
    NiBound skinned;
    std::memcpy(&skinned.radius, &bound.radius, sizeof(skinned.radius));
    const float previousRadius = skinned.radius;
    const float previousZ = bound.center.z;
    const float previousY = bound.center.y;
    const float previousX = bound.center.x;
    if (TestBit(flags, 13) && previousRadius != 0.0f) {
        return;
    }
    if (m_spSkinInstance) {
        skinned.center.x = NiPoint3::ZERO.x;
        skinned.center.y = NiPoint3::ZERO.y;
        skinned.center.z = NiPoint3::ZERO.z;
        // the radius is handled as raw bits throughout, like the saved copy above
        const std::uint32_t noRadius = 0;
        std::memcpy(&skinned.radius, &noRadius, sizeof(skinned.radius));
        m_spSkinInstance->ComputeBound(skinned);
        bound.TransformPoint(skinned.center, world);
        bound.radius = skinned.radius * world.scale;
    } else {
        bound.TransformBoundToWorld(m_spModelData->bound, world);
    }

    std::uint32_t currentFlags = flags;
    if (TestBit(currentFlags, 22)) {
        if (previousX == bound.center.x &&
            previousY == bound.center.y &&
            previousZ == bound.center.z &&
            previousRadius == bound.radius) {
            currentFlags |= kRenderUse;
        } else {
            currentFlags &= ~kRenderUse;
        }
        flags = currentFlags;
    }
}
