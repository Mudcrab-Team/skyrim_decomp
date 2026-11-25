// 0xff66c0 BSSubIndexTriShape::SetSegment
// Code origin: original reconstruction from pinned-image observations; declarations use the labelled sources.
// Source exposure: mixed
// SetSegment: CRASHLOGGER_PDB(59818@2026.10.24)
// BSSubIndexTriShape, SegmentData, segmentData, numSegments, unkSegCount, unk170, index, unkTriCount, unkFlags, numTris, flags: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
#include "BSSubIndexTriShape_ff66c0.h"

void BSSubIndexTriShape::SetSegment(std::uint32_t segment, std::uint32_t firstIndex,
                                      std::uint32_t triangleCount, std::uint8_t firstFlags,
                                      std::uint8_t secondFlags)
{
    segmentData[segment].index = firstIndex;
    segmentData[segment].unkTriCount = triangleCount;
    segmentData[segment].numTris = triangleCount;
    segmentData[segment].unkFlags = firstFlags;
    segmentData[segment].flags = secondFlags;
    unk170 = true;
}
