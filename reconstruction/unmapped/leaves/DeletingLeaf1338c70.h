// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1338c70: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1338c70
{
public:
    DeletingLeaf1338c70();
    virtual ~DeletingLeaf1338c70();  // compared: 0x1338c70
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1338c70) == 16, "size observed from the sized delete argument");
