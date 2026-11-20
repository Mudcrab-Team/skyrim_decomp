// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaffc74c0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaffc74c0
{
public:
    DeletingLeaffc74c0();
    virtual ~DeletingLeaffc74c0();  // compared: 0xfc74c0
    void* unknown08;
};
static_assert(sizeof(DeletingLeaffc74c0) == 16, "size observed from the sized delete argument");
