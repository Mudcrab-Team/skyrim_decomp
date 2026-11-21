// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeaf9d4ea0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf9d4ea0
{
public:
    DeletingLeaf9d4ea0();
    virtual ~DeletingLeaf9d4ea0();  // compared: 0x9d4ea0 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeaf9d4ea0) == 56, "size observed from the sized delete argument");
