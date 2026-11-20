// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf384b10: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf384b10
{
public:
    DeletingLeaf384b10();
    virtual ~DeletingLeaf384b10();  // compared: 0x384b10
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf384b10) == 16, "size observed from the sized delete argument");
