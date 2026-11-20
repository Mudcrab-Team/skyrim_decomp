// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1139440: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1139440
{
public:
    DeletingLeaf1139440();
    virtual ~DeletingLeaf1139440();  // compared: 0x1139440
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1139440) == 16, "size observed from the sized delete argument");
