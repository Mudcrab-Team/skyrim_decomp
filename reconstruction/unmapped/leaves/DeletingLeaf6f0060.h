// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf6f0060: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf6f0060
{
public:
    DeletingLeaf6f0060();
    virtual ~DeletingLeaf6f0060();  // compared: 0x6f0060
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf6f0060) == 16, "size observed from the sized delete argument");
