// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1243bd0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1243bd0
{
public:
    DeletingLeaf1243bd0();
    virtual ~DeletingLeaf1243bd0();  // compared: 0x1243bd0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1243bd0) == 16, "size observed from the sized delete argument");
