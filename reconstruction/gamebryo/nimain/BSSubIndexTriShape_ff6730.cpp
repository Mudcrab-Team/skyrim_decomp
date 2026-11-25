// Source exposure: binary-analysis.
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// Original body; name and partial layout from community-generated type evidence.
// BSSubIndexTriShape, ClearSegment: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xff6730 BSSubIndexTriShape::ClearSegment
#include "BSSubIndexTriShape_ff6730.h"

void BSSubIndexTriShape::ClearSegment(std::uint32_t segment)
{
    segmentData[segment].unkFlags = 0;
    segmentData[segment].unkTriCount = 0;
    segmentData[segment].numTris = 0;
    segmentData[segment].index = 0;
    unk170 = true;
}
