// Source exposure: mixed (target observations; permitted sibling naming/shape hints).
// Code origin: original; observed target layout and labelled names
// SPDX-License-Identifier: CC0-1.0
// PathingRequestOptimalLocation: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingRequest, Write, BSPathingStreamWrite, DoWriteFloat: SIBLING(fo4-private@1b765c70, author-permission)
// fMinDistance, fMaxDistance, fAbsoluteMinDistance, fAbsoluteMaxDistance: SYMBOLS(fo4-pdb)
// PathingRequest layout, PathingRequestOptimalLocation field offsets: OBSERVED
// BSPathingStreamWrite::Unknown: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
class BSPathingStreamWrite {
public:
    virtual void Unknown();
    virtual void DoWriteFloat(float value);
};
class PathingRequest {
public:
    void Write(BSPathingStreamWrite& stream);
    std::uint8_t reserved[0x100];
};
class PathingRequestOptimalLocation : public PathingRequest {
public:
    void Write(BSPathingStreamWrite& stream);
    float fMinDistance;
    float fMaxDistance;
    float fAbsoluteMinDistance;
    float fAbsoluteMaxDistance;
};
static_assert(offsetof(PathingRequestOptimalLocation, fMinDistance) == 0x100, "observed minimum distance offset");
