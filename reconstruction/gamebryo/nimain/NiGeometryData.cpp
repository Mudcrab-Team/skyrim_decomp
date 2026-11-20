// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xefbff0 NiGeometryData::GetActiveVertexCount
#include "NiGeometryData.h"

NiTriShapeData* NiGeometryData::AsTriShapeData()
{
    return nullptr;
}

NiTriStripsData* NiGeometryData::AsTriStripsData()
{
    return nullptr;
}

void NiGeometryData::SetActiveVertexCount(std::uint16_t)
{
}

std::uint16_t NiGeometryData::GetActiveVertexCount() const
{
    return activeVertexCount;
}
