// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1123de0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1123de0
{
public:
    DeletingLeaf1123de0();
    virtual ~DeletingLeaf1123de0();  // compared: 0x1123de0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1123de0) == 16, "size observed from the sized delete argument");
