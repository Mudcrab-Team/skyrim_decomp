// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf38ec80: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf38ec80
{
public:
    DeletingLeaf38ec80();
    virtual ~DeletingLeaf38ec80();  // compared: 0x38ec80
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf38ec80) == 16, "size observed from the sized delete argument");
