// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf5e8510: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf5e8510
{
public:
    DeletingLeaf5e8510();
    virtual ~DeletingLeaf5e8510();  // compared: 0x5e8510
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf5e8510) == 16, "size observed from the sized delete argument");
