// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf6bc830: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf6bc830
{
public:
    DeletingLeaf6bc830();
    virtual ~DeletingLeaf6bc830();  // compared: 0x6bc830
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf6bc830) == 16, "size observed from the sized delete argument");
