// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482750: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482750
{
public:
    DeletingLeaf1482750();
    virtual ~DeletingLeaf1482750();  // compared: 0x1482750
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1482750) == 16, "size observed from the sized delete argument");
