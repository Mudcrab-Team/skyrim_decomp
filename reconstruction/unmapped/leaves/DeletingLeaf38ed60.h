// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf38ed60: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf38ed60
{
public:
    DeletingLeaf38ed60();
    virtual ~DeletingLeaf38ed60();  // compared: 0x38ed60
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf38ed60) == 16, "size observed from the sized delete argument");
