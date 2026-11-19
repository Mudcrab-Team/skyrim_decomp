// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafd8e790: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafd8e790
{
public:
    DeletingLeafd8e790();
    virtual ~DeletingLeafd8e790();  // compared: 0xd8e790
    void* unknown08;
};
static_assert(sizeof(DeletingLeafd8e790) == 16, "size observed from the sized delete argument");
