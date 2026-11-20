// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafdb8db0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafdb8db0
{
public:
    DeletingLeafdb8db0();
    virtual ~DeletingLeafdb8db0();  // compared: 0xdb8db0
    void* unknown08;
};
static_assert(sizeof(DeletingLeafdb8db0) == 16, "size observed from the sized delete argument");
