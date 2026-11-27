// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestCover.cpp:100
// PathingCoverLocation, Write, LeftVertex, RightVertex, EdgeDirection, cCoverHeight, bStandCover, bHigherThanCrouch: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// bLeftEdgeOpen, bRightEdgeOpen, cEdge, cState, BSPathingLocation, BSPathingStreamWrite: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// PathingCoverLocation, Write: CRASHLOGGER_PDB(59818@2026.10.24)
// DoWriteFloat, DoWriteUChar, DoWriteBool, Point3, unk00, unk10: GUESS(low)
#pragma once

#include <cstdint>

class BSPathingStreamWrite
{
public:
    virtual void unk00();
    virtual void DoWriteFloat(float a_value);  // 01
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void DoWriteUChar(std::uint8_t a_value);  // 08
    virtual void unk09();
    virtual void DoWriteBool(bool a_value);  // 10
};

struct Point3
{
    float x;
    float y;
    float z;
};

// Location base without virtuals: the derived class puts its vtable pointer first.
class BSPathingLocation
{
public:
    void Write(BSPathingStreamWrite& a_stream) const;

    std::uint8_t unk00[0x30];
};

class PathingCoverLocation : public BSPathingLocation
{
public:
    virtual void Write(BSPathingStreamWrite& a_stream) const;  // compared: 0x4f47f0

    Point3 LeftVertex;           // 38
    Point3 RightVertex;          // 44
    Point3 EdgeDirection;        // 50
    std::uint8_t cCoverHeight;   // 5C
    bool bStandCover;            // 5D
    bool bHigherThanCrouch;      // 5E
    bool bLeftEdgeOpen;          // 5F
    bool bRightEdgeOpen;         // 60
    std::uint8_t cEdge;          // 61
    std::uint8_t cState;         // 62
};
