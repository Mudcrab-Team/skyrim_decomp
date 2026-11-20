// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf956740: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf956740
{
public:
    DeletingLeaf956740();
    virtual ~DeletingLeaf956740();  // compared: 0x956740
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf956740) == 16, "size observed from the sized delete argument");
