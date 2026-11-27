// Source exposure: binary-analysis.
// Code origin: declarations and layout reconstruction using the labelled sources.
// BSSubIndexTriShape, ClearSegment, SegmentData, segmentData, numSegments, unkSegCount, unk170, index, unkTriCount, unkFlags, numTris, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// prefix, padding09, padding11: GUESS(low); unrepresented storage.
#pragma once
#include <cstddef>
#include <cstdint>

struct SegmentData {
    std::uint32_t index;
    std::uint32_t unkTriCount;
    std::uint8_t unkFlags;
    std::uint8_t padding09[3];
    std::uint32_t numTris;
    std::uint8_t flags;
    std::uint8_t padding11[3];
};
static_assert(sizeof(SegmentData) == 0x14, "segment stride");
class BSSubIndexTriShape {
public:
    void ClearSegment(std::uint32_t segment);
    std::uint8_t prefix[0x160];
    SegmentData* segmentData;
    std::uint32_t numSegments;
    std::uint32_t unkSegCount;
    bool unk170;
};
static_assert(offsetof(BSSubIndexTriShape, segmentData) == 0x160, "segment array offset");
static_assert(offsetof(BSSubIndexTriShape, unk170) == 0x170, "dirty flag offset");
