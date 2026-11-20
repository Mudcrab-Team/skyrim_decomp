// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeaf8c5b90: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf8c5b90
{
public:
    DeletingLeaf8c5b90();
    virtual ~DeletingLeaf8c5b90();  // compared: 0x8c5b90 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeaf8c5b90) == 56, "size observed from the sized delete argument");
