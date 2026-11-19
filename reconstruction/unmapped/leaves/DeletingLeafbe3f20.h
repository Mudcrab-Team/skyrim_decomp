// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafbe3f20: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafbe3f20
{
public:
    DeletingLeafbe3f20();
    virtual ~DeletingLeafbe3f20();  // compared: 0xbe3f20
    void* unknown08;
};
static_assert(sizeof(DeletingLeafbe3f20) == 16, "size observed from the sized delete argument");
