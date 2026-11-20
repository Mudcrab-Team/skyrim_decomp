// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf7acaf0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf7acaf0
{
public:
    DeletingLeaf7acaf0();
    virtual ~DeletingLeaf7acaf0();  // compared: 0x7acaf0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf7acaf0) == 16, "size observed from the sized delete argument");
