// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf4a1350: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf4a1350
{
public:
    DeletingLeaf4a1350();
    virtual ~DeletingLeaf4a1350();  // compared: 0x4a1350
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf4a1350) == 16, "size observed from the sized delete argument");
