// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTriBasedGeomData, NiTriBasedGeomData::NiTriBasedGeomData, numTriangles: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiGeometryData, NiPoint2, NiPoint3, NiColorA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiGeometryData::NiGeometryData, DataFlags: SYMBOLS(fo4-pdb)
// unk08, unk10: GUESS(low)
#pragma once

#include <cstdint>

class NiPoint2;
class NiPoint3;
class NiColorA;

class NiObject
{
public:
    virtual ~NiObject();

private:
    std::uint8_t unk08[8];
};

class NiGeometryData : public NiObject
{
public:
    enum class DataFlags : std::uint32_t;

protected:
    NiGeometryData(std::uint16_t vertexCount, NiPoint3* vertices, NiPoint3* normals,
        NiColorA* colors, NiPoint2* textureCoords, std::uint16_t textureSets, DataFlags flags);

private:
    std::uint8_t unk10[0x58];
};

class NiTriBasedGeomData : public NiGeometryData
{
public:
    NiTriBasedGeomData(std::uint16_t vertexCount, NiPoint3* vertices, NiPoint3* normals,
        NiColorA* colors, NiPoint2* textureCoords, std::uint16_t textureSets, DataFlags flags,
        std::uint16_t triangleCount);

private:
    std::uint16_t numTriangles;
};
