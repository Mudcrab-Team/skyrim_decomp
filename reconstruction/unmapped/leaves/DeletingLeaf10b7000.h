// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeaf10b7000: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf10b7000
{
public:
    DeletingLeaf10b7000();
    virtual ~DeletingLeaf10b7000();  // compared: 0x10b7000 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeaf10b7000) == 56, "size observed from the sized delete argument");
