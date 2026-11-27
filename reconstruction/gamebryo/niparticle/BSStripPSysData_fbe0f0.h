// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, NiColorA, StripPointData, StripData, BSStripPSysData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z, NiColorA::r, NiColorA::g, NiColorA::b, NiColorA::a: CRASHLOGGER_PDB(59818@2026.10.24)
// StripPointData::ptCenter, StripPointData::pointColor, StripPointData::pointSize, StripPointData::pointRadius, StripData::ptRingBuffer, BSStripPSysData::stripData: CRASHLOGGER_PDB(59818@2026.10.24)
// StripData::segmentCount: CRASHLOGGER_PDB(59818@2026.10.24) OBSERVED; signed load in image
// gDefaultStripColor, StripPointData::verts, StripPointData::tangentSideVectors, StripPointData::unk3C, StripPointData::unk90, StripPointData::unkB4, StripData::unk08, StripData::unk10, BSStripPSysData::unk00, BSStripPSysData::color, BSStripPSysData::unk40: GUESS(low)
// BSStripPSysData::Functionfbe0f0, BSStripPSysData::Functionfbe1b0, BSStripPSysData::Functionfbe1f0, BSStripPSysData::Functionfbe220, BSStripPSysData::Functionfbe250, BSStripPSysData::Functionfbe280: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiColorA
{
    float r;
    float g;
    float b;
    float a;
};

extern NiColorA gDefaultStripColor;

struct StripPointData
{
    NiPoint3 ptCenter;               // 00
    NiPoint3 verts[4];               // 0C
    std::uint8_t unk3C[0x3C];        // 3C
    NiPoint3 tangentSideVectors[2];  // 78
    std::uint8_t unk90[0x0C];        // 90
    NiColorA pointColor;             // 9C
    float pointSize;                 // AC
    float pointRadius;               // B0
    std::uint32_t unkB4;             // B4
};
static_assert(offsetof(StripPointData, tangentSideVectors) == 0x78, "tangentSideVectors offset");
static_assert(offsetof(StripPointData, pointColor) == 0x9C, "pointColor offset");
static_assert(offsetof(StripPointData, pointSize) == 0xAC, "pointSize offset");
static_assert(offsetof(StripPointData, pointRadius) == 0xB0, "pointRadius offset");
static_assert(sizeof(StripPointData) == 0xB8, "StripPointData size");

struct StripData
{
    StripPointData* ptRingBuffer;  // 00
    std::uint8_t unk08[0x04];      // 08
    std::int32_t segmentCount;     // 0C
    std::uint8_t unk10[0x18];      // 10
};
static_assert(offsetof(StripData, segmentCount) == 0x0C, "segmentCount offset");
static_assert(sizeof(StripData) == 0x28, "StripData size");

class BSStripPSysData
{
public:
    float Functionfbe0f0(std::uint16_t a_stripIndex);
    const NiColorA* Functionfbe1b0(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex);
    float Functionfbe1f0(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex);
    float Functionfbe220(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex);
    NiPoint3* Functionfbe250(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex);
    NiPoint3* Functionfbe280(std::uint16_t a_stripIndex, std::uint16_t a_pointIndex);

    std::uint8_t unk00[0x38];
    NiColorA* color;
    std::uint8_t unk40[0x68];
    StripData* stripData;
};
static_assert(offsetof(BSStripPSysData, color) == 0x38, "color offset");
static_assert(offsetof(BSStripPSysData, stripData) == 0xA8, "stripData offset");
