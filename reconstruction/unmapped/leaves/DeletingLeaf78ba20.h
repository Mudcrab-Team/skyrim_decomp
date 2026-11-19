// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf78ba20: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf78ba20
{
public:
    DeletingLeaf78ba20();
    virtual ~DeletingLeaf78ba20();  // compared: 0x78ba20
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf78ba20) == 16, "size observed from the sized delete argument");
