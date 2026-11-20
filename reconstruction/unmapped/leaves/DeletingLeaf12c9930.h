// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9930: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9930
{
public:
    DeletingLeaf12c9930();
    virtual ~DeletingLeaf12c9930();  // compared: 0x12c9930
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf12c9930) == 16, "size observed from the sized delete argument");
