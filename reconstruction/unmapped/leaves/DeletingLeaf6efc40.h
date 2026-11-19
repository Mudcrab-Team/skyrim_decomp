// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf6efc40: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf6efc40
{
public:
    DeletingLeaf6efc40();
    virtual ~DeletingLeaf6efc40();  // compared: 0x6efc40
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf6efc40) == 16, "size observed from the sized delete argument");
