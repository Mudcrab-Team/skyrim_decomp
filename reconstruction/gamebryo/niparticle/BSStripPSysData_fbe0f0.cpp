// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSStripPSysData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSStripPSysData::Functionfbe0f0, BSStripPSysData::Functionfbe1b0, BSStripPSysData::Functionfbe1f0, BSStripPSysData::Functionfbe220, BSStripPSysData::Functionfbe250, BSStripPSysData::Functionfbe280: GUESS(low)
// 0xfbe0f0 BSStripPSysData::Functionfbe0f0
// 0xfbe1b0 BSStripPSysData::Functionfbe1b0
// 0xfbe1f0 BSStripPSysData::Functionfbe1f0
// 0xfbe220 BSStripPSysData::Functionfbe220
// 0xfbe250 BSStripPSysData::Functionfbe250
// 0xfbe280 BSStripPSysData::Functionfbe280
#include "BSStripPSysData_fbe0f0.h"

// Compute the inverse segment span for a strip.
float BSStripPSysData::Functionfbe0f0(std::uint16_t a_stripIndex)
{
    return 1.0f / (static_cast<float>(stripData[a_stripIndex].segmentCount) - 1.0f);
}

// Return the strip point color when vertex colors are enabled, otherwise the default color.
const NiColorA* BSStripPSysData::Functionfbe1b0(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex)
{
    if (color) {
        return &stripData[a_stripIndex].ptRingBuffer[a_pointIndex].pointColor;
    }
    return &gDefaultStripColor;
}

// Return the stored size for a strip point.
float BSStripPSysData::Functionfbe1f0(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex)
{
    return stripData[a_stripIndex].ptRingBuffer[a_pointIndex].pointSize;
}

// Return the stored radius for a strip point.
float BSStripPSysData::Functionfbe220(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex)
{
    return stripData[a_stripIndex].ptRingBuffer[a_pointIndex].pointRadius;
}

// Return the vertex array for a strip point.
NiPoint3* BSStripPSysData::Functionfbe250(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex)
{
    return stripData[a_stripIndex].ptRingBuffer[a_pointIndex].verts;
}

// Return the tangent side vectors for a strip point.
NiPoint3* BSStripPSysData::Functionfbe280(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex)
{
    return stripData[a_stripIndex].ptRingBuffer[a_pointIndex].tangentSideVectors;
}
