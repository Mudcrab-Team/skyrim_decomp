// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf2f8e30: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf2f8e30
{
public:
    DeletingLeaf2f8e30();
    virtual ~DeletingLeaf2f8e30();  // compared: 0x2f8e30
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf2f8e30) == 16, "size observed from the sized delete argument");
