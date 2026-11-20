// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf7acac0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf7acac0
{
public:
    DeletingLeaf7acac0();
    virtual ~DeletingLeaf7acac0();  // compared: 0x7acac0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf7acac0) == 16, "size observed from the sized delete argument");
