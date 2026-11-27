// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x30e1b0 TESWorldSpace::ApplyWorldMapOffset
// Adapted bodies: none
#include "TESWorldSpace_30e1b0.h"

// Transform a world position by this worldspace's map scale and offset, or apply the inverse transform.
void TESWorldSpace::ApplyWorldMapOffset(NiPoint3& position, bool reverse) const
{
    if (reverse) {
        position.x -= worldMapOffsetData.mapOffsetX;
        position.y -= worldMapOffsetData.mapOffsetY;
        position.z -= worldMapOffsetData.mapOffsetZ;
    }

    const float scale = worldMapOffsetData.mapScale;
    if (scale != 1.0f && scale != 0.0f) {
        float centerX;
        float centerY;
        if ((flags & 0x40) != 0) {
            centerX = static_cast<float>(static_cast<std::int32_t>(fixedCenter.x) << 12) + 2048.0f;
            centerY = static_cast<float>(static_cast<std::int32_t>(fixedCenter.y) << 12) + 2048.0f;
        } else {
            centerX = (maximumCoords.x + minimumCoords.x) * 0.5f;
            centerY = (maximumCoords.y + minimumCoords.y) * 0.5f;
        }

        NiPoint3 offset;
        offset.x = position.x - centerX;
        offset.y = position.y - centerY;
        offset.z = position.z;

        const float factor = reverse ? (1.0f / scale) : scale;
        offset.x *= factor;
        offset.y *= factor;
        offset.z *= factor;

        position.x = offset.x + centerX;
        position.y = offset.y + centerY;
        position.z = offset.z;
    }

    if (!reverse) {
        position.x += worldMapOffsetData.mapOffsetX;
        position.y += worldMapOffsetData.mapOffsetY;
        position.z += worldMapOffsetData.mapOffsetZ;
    }
}
