// 0xff66c0 BSSubIndexTriShape::SetSegment
// Source exposure: mixed
// Code origin: original minimal declarations and layout views using the labelled sources.
// BSSubIndexTriShape, SegmentData, segmentData, numSegments, unkSegCount, unk170, index, unkTriCount, unkFlags, numTris, flags: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// SetSegment: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstddef>
#include <cstdint>

struct SegmentData {
    std::uint32_t index;
    std::uint32_t unkTriCount;
    std::uint8_t unkFlags;
    std::uint32_t numTris;
    std::uint8_t flags;
};
class BSSubIndexTriShape {
public:
    void SetSegment(std::uint32_t segment, std::uint32_t firstIndex,
                        std::uint32_t triangleCount, std::uint8_t firstFlags,
                        std::uint8_t secondFlags);
    unsigned char prefix[0x160];
    SegmentData* segmentData;
    std::uint32_t numSegments;
    std::uint32_t unkSegCount;
    bool unk170;
};
static_assert(sizeof(SegmentData) == 0x14, "segment stride");
static_assert(offsetof(SegmentData, numTris) == 0x0C, "triangle count offset");
static_assert(offsetof(SegmentData, flags) == 0x10, "segment flags offset");
static_assert(offsetof(BSSubIndexTriShape, segmentData) == 0x160, "segment array offset");
static_assert(offsetof(BSSubIndexTriShape, unk170) == 0x170, "update flag offset");
