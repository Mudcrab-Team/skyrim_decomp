// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf4e30a0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf4e30a0
{
public:
    DeletingLeaf4e30a0();
    virtual ~DeletingLeaf4e30a0();  // compared: 0x4e30a0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf4e30a0) == 16, "size observed from the sized delete argument");
