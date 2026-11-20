// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf10ddf00: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf10ddf00
{
public:
    DeletingLeaf10ddf00();
    virtual ~DeletingLeaf10ddf00();  // compared: 0x10ddf00
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf10ddf00) == 16, "size observed from the sized delete argument");
