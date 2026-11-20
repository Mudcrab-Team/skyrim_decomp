// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x20b3d0 (reconstruction/unmapped/wrappers/F004Represented20b3d0.cpp); no external declaration or body reused.
// DeletingLeafa7e2c0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafa7e2c0
{
public:
    DeletingLeafa7e2c0();
    virtual ~DeletingLeafa7e2c0();  // compared: 0xa7e2c0 (scalar deleting destructor)
    unsigned char unknown08[48];
};
static_assert(sizeof(DeletingLeafa7e2c0) == 56, "size observed from the sized delete argument");
