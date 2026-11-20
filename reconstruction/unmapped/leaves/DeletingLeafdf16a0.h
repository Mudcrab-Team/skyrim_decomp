// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafdf16a0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafdf16a0
{
public:
    DeletingLeafdf16a0();
    virtual ~DeletingLeafdf16a0();  // compared: 0xdf16a0
    void* unknown08;
};
static_assert(sizeof(DeletingLeafdf16a0) == 16, "size observed from the sized delete argument");
