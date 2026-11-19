// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1139410: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1139410
{
public:
    DeletingLeaf1139410();
    virtual ~DeletingLeaf1139410();  // compared: 0x1139410
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1139410) == 16, "size observed from the sized delete argument");
