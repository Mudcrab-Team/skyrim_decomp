// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462fe0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462fe0
{
public:
    DeletingLeaf1462fe0();
    virtual ~DeletingLeaf1462fe0();  // compared: 0x1462fe0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1462fe0) == 16, "size observed from the sized delete argument");
