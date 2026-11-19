// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf40b430: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf40b430
{
public:
    DeletingLeaf40b430();
    virtual ~DeletingLeaf40b430();  // compared: 0x40b430
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf40b430) == 16, "size observed from the sized delete argument");
