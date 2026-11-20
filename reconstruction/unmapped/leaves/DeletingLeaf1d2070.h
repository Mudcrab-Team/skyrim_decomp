// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1d2070: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1d2070
{
public:
    DeletingLeaf1d2070();
    virtual ~DeletingLeaf1d2070();  // compared: 0x1d2070
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1d2070) == 16, "size observed from the sized delete argument");
