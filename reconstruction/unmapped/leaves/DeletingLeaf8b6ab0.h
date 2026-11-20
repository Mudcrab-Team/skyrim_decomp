// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeaf8b6ab0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf8b6ab0
{
public:
    DeletingLeaf8b6ab0();
    virtual ~DeletingLeaf8b6ab0();  // compared: 0x8b6ab0 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeaf8b6ab0) == 56, "size observed from the sized delete argument");
