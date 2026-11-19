// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf257170: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf257170
{
public:
    DeletingLeaf257170();
    virtual ~DeletingLeaf257170();  // compared: 0x257170
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf257170) == 16, "size observed from the sized delete argument");
