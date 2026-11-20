// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeafcd85e0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafcd85e0
{
public:
    DeletingLeafcd85e0();
    virtual ~DeletingLeafcd85e0();  // compared: 0xcd85e0 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeafcd85e0) == 56, "size observed from the sized delete argument");
