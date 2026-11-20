// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf32c9c0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf32c9c0
{
public:
    DeletingLeaf32c9c0();
    virtual ~DeletingLeaf32c9c0();  // compared: 0x32c9c0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf32c9c0) == 16, "size observed from the sized delete argument");
