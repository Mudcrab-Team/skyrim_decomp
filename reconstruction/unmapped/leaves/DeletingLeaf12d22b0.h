// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf12d22b0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12d22b0
{
public:
    DeletingLeaf12d22b0();
    virtual ~DeletingLeaf12d22b0();  // compared: 0x12d22b0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf12d22b0) == 16, "size observed from the sized delete argument");
