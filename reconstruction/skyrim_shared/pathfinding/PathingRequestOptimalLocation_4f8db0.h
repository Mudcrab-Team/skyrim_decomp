// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; observed target layout and labelled names
// SPDX-License-Identifier: CC0-1.0
// PathingRequestOptimalLocation, PathingRequestOptimalLocation::Read: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingRequest, BSPathingStreamRead, DoReadFloat: SIBLING(fo4-private@1b765c70, author-permission)
// fMinDistance, fMaxDistance, fAbsoluteMinDistance, fAbsoluteMaxDistance: SYMBOLS(fo4-pdb)
// PathingRequest layout, PathingRequestOptimalLocation field offsets: OBSERVED
// BSPathingStreamRead::Unknown: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

class BSPathingStreamRead
{
public:
    virtual void Unknown();
    virtual void DoReadFloat(float& value);
};
class PathingRequest
{
public:
    void Read(BSPathingStreamRead& stream);
    std::uint8_t unknown[0x100];
};
class PathingRequestOptimalLocation : public PathingRequest
{
public:
    void Read(BSPathingStreamRead& stream);
    float fMinDistance;
    float fMaxDistance;
    float fAbsoluteMinDistance;
    float fAbsoluteMaxDistance;
};
static_assert(offsetof(PathingRequestOptimalLocation, fMinDistance) == 0x100, "observed minimum distance offset");
