// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf5e5250: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf5e5250
{
public:
    DeletingLeaf5e5250();
    virtual ~DeletingLeaf5e5250();  // compared: 0x5e5250
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf5e5250) == 16, "size observed from the sized delete argument");
