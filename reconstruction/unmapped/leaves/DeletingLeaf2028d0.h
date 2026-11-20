// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf2028d0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf2028d0
{
public:
    DeletingLeaf2028d0();
    virtual ~DeletingLeaf2028d0();  // compared: 0x2028d0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf2028d0) == 16, "size observed from the sized delete argument");
