// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf384b40: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf384b40
{
public:
    DeletingLeaf384b40();
    virtual ~DeletingLeaf384b40();  // compared: 0x384b40
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf384b40) == 16, "size observed from the sized delete argument");
