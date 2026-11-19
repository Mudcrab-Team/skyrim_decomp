// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1e78b0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1e78b0
{
public:
    DeletingLeaf1e78b0();
    virtual ~DeletingLeaf1e78b0();  // compared: 0x1e78b0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1e78b0) == 16, "size observed from the sized delete argument");
