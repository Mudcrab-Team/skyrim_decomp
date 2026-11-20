// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafec3d50: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafec3d50
{
public:
    DeletingLeafec3d50();
    virtual ~DeletingLeafec3d50();  // compared: 0xec3d50
    void* unknown08;
};
static_assert(sizeof(DeletingLeafec3d50) == 16, "size observed from the sized delete argument");
