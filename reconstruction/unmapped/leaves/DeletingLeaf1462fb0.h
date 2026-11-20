// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462fb0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462fb0
{
public:
    DeletingLeaf1462fb0();
    virtual ~DeletingLeaf1462fb0();  // compared: 0x1462fb0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1462fb0) == 16, "size observed from the sized delete argument");
