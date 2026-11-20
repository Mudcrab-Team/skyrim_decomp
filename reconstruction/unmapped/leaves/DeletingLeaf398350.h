// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf398350: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf398350
{
public:
    DeletingLeaf398350();
    virtual ~DeletingLeaf398350();  // compared: 0x398350
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf398350) == 16, "size observed from the sized delete argument");
