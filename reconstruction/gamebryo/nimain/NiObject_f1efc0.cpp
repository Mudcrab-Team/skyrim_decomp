// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf1efc0 NiTriBasedGeomData::NiTriBasedGeomData
// Adapted bodies: NiTriBasedGeomData::NiTriBasedGeomData follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nitribasedgeomdata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nitribasedgeomdata.cpp:8
#include "NiObject_f1efc0.h"

NiTriBasedGeomData::NiTriBasedGeomData(std::uint16_t vertexCount, NiPoint3* vertices,
    NiPoint3* normals, NiColorA* colors, NiPoint2* textureCoords, std::uint16_t textureSets,
    DataFlags flags, std::uint16_t triangleCount)
    : NiGeometryData(vertexCount, vertices, normals, colors, textureCoords, textureSets, flags),
      numTriangles(triangleCount)
{
}
